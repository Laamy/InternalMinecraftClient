#include <windows.h>
#include <MinHook.h>
#include <map>

// SDK
#include "SDK/Actor.h"
#include "Client/Hooks/Actor.h"
#include "dllmain.h"

#define PI 3.14159265359 // 3.14159265359

typedef void(__thiscall* tick)(Actor*);
tick _tick;

typedef void(__thiscall* key)(uint64_t, bool);
key _key;

std::map<uint64_t, bool> keymap = std::map<uint64_t, bool>();

void keyCallback(uint64_t c, bool v) { // Store key infomation inside our own keymap ;p
    keymap[c] = v;
    _key(c, v);
};

bool wasHeld = false;

void callback(Actor* player) {

    if (keymap[(int)'C'])
        player->setFieldOfView(0.2f);
    else player->setFieldOfView(1);
};

void Init(HMODULE c) {
    if (MH_Initialize() == MH_OK) {

        uintptr_t baseAddr = (uintptr_t)GetModuleHandleA("Minecraft.Windows.exe");

        uintptr_t hookAddr = (uintptr_t)(baseAddr + 0x1D6A220); // F3 0F 10 81 ? ? ? ? 41 0F 2F 00
        uintptr_t keymapAddr = (uintptr_t)(baseAddr + 0x775230);// 48 89 5C 24 08 57 48 83 EC ? 8B 05 ? ? ? ? 8B DA

        if (MH_CreateHook((void*)hookAddr, &callback, reinterpret_cast<LPVOID*>(&_tick)) == MH_OK) {
            MH_EnableHook((void*)hookAddr);
        };
        if (MH_CreateHook((void*)keymapAddr, &keyCallback, reinterpret_cast<LPVOID*>(&_key)) == MH_OK) {
            MH_EnableHook((void*)keymapAddr);
        };
    };
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Init, hModule, 0, 0);
    }
    return TRUE;
}
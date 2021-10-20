#include <windows.h>
#include <MinHook.h>
#include <map>

// SDK
#include "SDK/Actor.h"
#include "Utils/Utils.h"
#include "SDK/MinecraftUIRenderContext.h"

#define PI 3.14159265359 // 3.14159265359

typedef void(__thiscall* tick)(Actor*, void* a2);
tick _tick;

typedef void(__thiscall* key)(uint64_t, bool);
key _key;

std::map<uint64_t, bool> keymap = std::map<uint64_t, bool>();

std::map<uint64_t, uint64_t> map = std::map<uint64_t, uint64_t>();

void keyCallback(uint64_t c, bool v) { // Store key infomation inside our own keymap ;p
    keymap[c] = v;
    _key(c, v);
};

bool wasHeld = false;

void callback(Actor* player, void* a2) {
    //player->InitOffsets(map); // offset init doesnt work

    if (keymap[(int)'C'])
        player->setFieldOfView(0.2f);
    else player->setFieldOfView(1);

    _tick(player, a2);
};

void Init(HMODULE c) {
    if (MH_Initialize() == MH_OK) { // CROSS VERSION! (time to test omfg)

        // Function hooks
        uintptr_t hookAddr = Mem::findSig("48 83 EC ? 80 B9 ? ? ? ? ? 75 23");
        uintptr_t keymapAddr = Mem::findSig("E9 ? ? ? ? 57 48 83");
        
        // Offset scanning
        //map[0] = *reinterpret_cast<int*>(Mem::findSig("F3 0F 59 B3 ? ? ? ? 0F") + 4);

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
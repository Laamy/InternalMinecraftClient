#include <windows.h>
#include <MinHook.h>
#include <map>

// SDK
#include "SDK/Actor.h"
#include "Utils/Utils.h"
#include "Utils/RenderUtils.h"

#define PI 3.14159265359 // 3.14159265359

typedef void(__thiscall* tick)(Actor*, void* a2);
tick _tick;

typedef void(__thiscall* key)(uint64_t, bool);
key _key;
 
typedef void(__thiscall* render)(void* a1, MinecraftUIRenderContext* ctx);
render _render;

std::map<uint64_t, bool> keymap = std::map<uint64_t, bool>();
std::map<uint64_t, bool> cancelKeymap = std::map<uint64_t, bool>();

Actor* plr = nullptr;

void keyUp(uint64_t c) {
    if (plr == nullptr) return;
    if (c == (int)'F') {
        plr->Velocity = Vector3(0, 0, 0);
    }
};

void keyDown(uint64_t c) {
    if (plr == nullptr) return;
};

void keyCallback(uint64_t c, bool v) { // Store key infomation inside our own keymap ;p
    if (v == false) {
        keyUp(c);
    }
    else
    { keyDown(c); }

    keymap[c] = v;
    if (cancelKeymap[c] == false)
        _key(c, v);
};

bool cancelUiRender = false;

RenderUtils renderUtil = RenderUtils();

Vector2 offsetStokes = Vector2(25, 25);

void tCallback(void* a1, MinecraftUIRenderContext* ctx) {

    if (ctx != nullptr && a1 != nullptr)
        if (cancelUiRender == false)
            _render(a1, ctx);

    if (plr == nullptr || ctx == nullptr || a1 == nullptr) {
        renderUtil.ctx == nullptr;
        return;
    }

    if (renderUtil.ctx == nullptr)
        renderUtil.Init(ctx);

    //renderUtil.DrawOutline(Vector2(10, 10), Vector2(52, 80), _RGB(33, 33, 33, 128), 2);

    if (keymap[38])  offsetStokes.y--;
    if (keymap[40])  offsetStokes.y++;
    if (keymap[37])  offsetStokes.x--;
    if (keymap[39])  offsetStokes.x++;

    if (keymap[(int)'W']) { renderUtil.Draw(Vector2(21 + offsetStokes.x, offsetStokes.y), Vector2(20, 20), _RGB(55, 55, 55, 160)); }
    else { renderUtil.Draw(Vector2(21 + offsetStokes.x, offsetStokes.y), Vector2(20, 20), _RGB(44, 44, 44, 160)); }
    if (keymap[(int)'A']) { renderUtil.Draw(Vector2(offsetStokes.x, 21 + offsetStokes.y), Vector2(20, 20), _RGB(55, 55, 55, 160)); }
    else { renderUtil.Draw(Vector2(offsetStokes.x, 21 + offsetStokes.y), Vector2(20, 20), _RGB(44, 44, 44, 160)); }
    if (keymap[(int)'S']) { renderUtil.Draw(Vector2(21 + offsetStokes.x, 21 + offsetStokes.y), Vector2(20, 20), _RGB(55, 55, 55, 160)); }
    else { renderUtil.Draw(Vector2(21 + offsetStokes.x, 21 + offsetStokes.y), Vector2(20, 20), _RGB(44, 44, 44, 160)); }
    if (keymap[(int)'D']) { renderUtil.Draw(Vector2(21 * 2 + offsetStokes.x, 21 + offsetStokes.y), Vector2(20, 20), _RGB(55, 55, 55, 160)); }
    else { renderUtil.Draw(Vector2(21 * 2 + offsetStokes.x, 21 + offsetStokes.y), Vector2(20, 20), _RGB(44, 44, 44, 160)); }
    if (keymap[(int)' ']) { renderUtil.Draw(Vector2(offsetStokes.x, 42 + offsetStokes.y), Vector2(62, 20), _RGB(55, 55, 55, 160)); }
    else { renderUtil.Draw(Vector2(offsetStokes.x, 42 + offsetStokes.y), Vector2(62, 20), _RGB(44, 44, 44, 160)); }

};

int flicker = 0;

void callback(Actor* player, void* a2) {

    if (player == nullptr) return;

    if (keymap[(int)'C']) {
        player->SetFieldOfView(0.2f);
        cancelUiRender = true;
    }
    else {
        player->SetFieldOfView(1);
        cancelUiRender = false;
    }

    if (keymap[(int)'F']) {
        auto speedMod = 4.0f;

        float calcYaw = (player->CameraRots.y + 90.0f) * (PI / 180.0f);
        
        player->Velocity.x = cos(calcYaw) * speedMod;
        player->Velocity.y = 0.05f * speedMod;
        player->Velocity.z = sin(calcYaw) * speedMod;

        if (flicker >= 100) {
            player->Velocity.y = -1.25f;
            flicker = 0;
        }
        flicker++;
    }

    //_key(0x11, true);

    plr = player;

    _tick(player, a2);
};

void Init(HMODULE c) {
    if (MH_Initialize() == MH_OK) {

        // Function hooks
        uintptr_t hookAddr = Mem::findSig("48 83 EC ? 80 B9 ? ? ? ? ? 75 23");
        uintptr_t keymapAddr = Mem::findSig("48 89 5C 24 08 57 48 83 EC ? 8B 05 ? ? ? ? 8B DA 89"); // 48 89 5C 24 08 57 48 83 EC ? 8B 05 ? ? ? ? 8B
        uintptr_t renderCtx = Mem::findSig("48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B FA 48 89 54 24 ? 4C 8B");
        
        if (MH_CreateHook((void*)hookAddr, &callback, reinterpret_cast<LPVOID*>(&_tick)) == MH_OK) {
            MH_EnableHook((void*)hookAddr);
        };
        if (MH_CreateHook((void*)keymapAddr, &keyCallback, reinterpret_cast<LPVOID*>(&_key)) == MH_OK) {
            MH_EnableHook((void*)keymapAddr);
        };
        if (MH_CreateHook((void*)renderCtx, &tCallback, reinterpret_cast<LPVOID*>(&_render)) == MH_OK) {
            MH_EnableHook((void*)renderCtx);
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
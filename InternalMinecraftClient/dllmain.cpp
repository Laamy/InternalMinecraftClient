#include <windows.h>
#include <MinHook.h>
#include <map>
#include <vector>
#include <Psapi.h>
#include <string>

#define _logf(str)  OutputDebugString(str)

// SDK
#include "SDK/Actor.h"
#include "SDK/GuiData.h"
#include "SDK/ClientInstance.h"

// Utils
#include "Utils/Utils.h"
#include "Utils/RenderUtils.h"
#include "ClientBase/Module.h"
#include "ClientBase/ModuleHandler.h"

#define PI 3.14159265359 // 3.14159265359

typedef void(__thiscall* tick)(ClientInstance* clientinstance, void* a2);
tick _tick;

typedef void(__thiscall* key)(uint64_t keyId, bool held);
key _key;

typedef void(__thiscall* mouse)(bool held, uintptr_t keyId, void* a3);
mouse _mouse;
 
typedef void(__thiscall* render)(void* a1, MinecraftUIRenderContext* ctx);
render _render;

std::map<uint64_t, bool> keymap = std::map<uint64_t, bool>();
std::map<uint64_t, bool> beforeKeymap = std::map<uint64_t, bool>();

std::map<uint64_t, bool> mousemap = std::map<uint64_t, bool>();

std::vector<std::string> categories = std::vector<std::string>();
std::vector<Vector2> categoryPos = std::vector<Vector2>();
ModuleHandler handler = ModuleHandler();

std::map<uint64_t, bool> modulesEnabled = std::map<uint64_t, bool>();

bool cancelUiRender = false;
bool renderClickUI = false;

RenderUtils renderUtil = RenderUtils();
GuiData* acs;
class BitmapFont* font;

int frame = 0;

void keyCallback(uint64_t c, bool v) { // Store key infomation inside our own keymap ;p
    if (c == 0x2D && keymap[c] == false && v == true) {
        renderClickUI = !renderClickUI;
    }
    keymap[c] = v;
    _key(c, v);
};

void mouseCallback(bool held, uintptr_t keyId, void* a3) {
    mousemap[keyId] = held;
    _mouse(held, keyId, a3);
};

void tCallback(void* a1, MinecraftUIRenderContext* ctx) {
    if (renderUtil.ctx == nullptr && font != nullptr)
        renderUtil.Init(ctx, acs, font);

    if (renderUtil.ctx == nullptr || font == nullptr) return;

    if (cancelUiRender == false)
        _render(a1, ctx);

    handler.FrameRender(&renderUtil);

    frame++;
    if (frame == 3) { // stop from rendering 3 times a frame
        if (renderClickUI) {
            renderUtil.Draw(Vector2(0, 0), renderUtil.guiData->scaledResolution, _RGB(33, 33, 33, 150));

            int cat = 0;
            for (std::string x : categories) {
                renderUtil.Draw(Vector2((float)(70 + (cat * 60)), 80), Vector2(48, 10), _RGB(33, 33, 33));
                auto catText = TextHolder(x); // (ctx->getLineLength(font, &catText, 1) / 2)
                renderUtil.DrawString(Vector2(95 + (cat * 60) - (ctx->getLineLength(font, &catText, 0.6f) / 2), 165), _RGB(255, 255, 255), catText, font, 0.6f);
                int catMod = 0;
                for (int i = 0; i < handler.modules.size(); ++i) {
                    if (handler.modules[i]->category == x) {
                        auto moduleBtnInfo = TextHolder(handler.modules[i]->name);
                        auto cda = renderUtil.DrawButtonText(Vector2((float)(70 + (cat * 60)), 90 + (catMod * 10)), Vector2(48, 10), _RGB(55, 55, 55), _RGB(44, 44, 44), _RGB(40, 40, 40), renderUtil.guiData->scaledMousePos(), keymap[(int)' '],
                            moduleBtnInfo, font, 0.6f, Vector2(24 - (ctx->getLineLength(font, &moduleBtnInfo, 0.6f) / 2), 4), handler.modules[i]->enabled);
                        if (cda && keymap[(int)' '] && beforeKeymap[i] == false) {
                            handler.modules[i]->enabled = !handler.modules[i]->enabled;
                        }
                        beforeKeymap[i] = keymap[(int)' '];
                        catMod++;
                    }
                }
                cat++;
            }
        }

        frame = 0;
    }

    for (int i = 0; i < handler.modules.size(); i++)
        modulesEnabled[i] = handler.modules[i]->enabled;
};

void callback(ClientInstance* ci, void* a2) {

    acs = ci->guiData;
    font = ci->mcGame->defaultGameFont;

    for (auto mod : handler.modules)
        if (ci->isInGame() && mod->enabled)
            mod->OnTick(ci);

    _tick(ci, a2);
};

void Init(HMODULE c) {
    if (MH_Initialize() == MH_OK) {

        handler.InitModules();

        for (auto mod : handler.modules) {
            bool addCategory = true;
            for (auto cat : categories) {
                if (mod->category == cat) addCategory = false;
            }
            if (addCategory)
                categories.push_back(mod->category);
        }

        // Function hooks
        uintptr_t keymapAddr = Mem::findSig("48 89 5C 24 08 57 48 83 EC ? 8B 05 ? ? ? ? 8B DA 89");
        uintptr_t hookAddr = Mem::findSig("48 8B 01 48 8D 54 24 ? FF 90 ? ? ? ? 90 48 8B 08 48 85 ? 0F 84 ? ? ? ? 48 8B 58 08 48 85 DB 74 0B F0 FF 43 08 48 8B 08 48 8B 58 08 48 89 4C 24 20 48 89 5C 24 28 48 8B 09 48 8B 01 4C 8B C7 48 8B");
        //uintptr_t mouseAddr = Mem::findSig("48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 57 41 54 41 55 41 56 41 57 48 83 EC ? 44 0F B7 BC 24 ? ? ? ? 48 8B ");
        uintptr_t renderCtx = Mem::findSig("48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B FA 48 89 54 24 ? 4C 8B");

        _logf(L"[TreroInternal]: Hooking functions...\n");

        if (MH_CreateHook((void*)keymapAddr, &keyCallback, reinterpret_cast<LPVOID*>(&_key)) == MH_OK) {
            MH_EnableHook((void*)keymapAddr);
            //memcpy((void*)keymapAddr, copy.inlineText, 0x1000);
            _logf(L"[TreroInternal]: Keymap hooked!\n");
        };
        if (MH_CreateHook((void*)hookAddr, &callback, reinterpret_cast<LPVOID*>(&_tick)) == MH_OK) {
            MH_EnableHook((void*)hookAddr);
            _logf(L"[TreroInternal]: ClientInstance hooked!\n");
        };
        //if (MH_CreateHook((void*)mouseAddr, &mouseCallback, reinterpret_cast<LPVOID*>(&_mouse)) == MH_OK) {
        //    MH_EnableHook((void*)mouseAddr);
        //};
        if (MH_CreateHook((void*)renderCtx, &tCallback, reinterpret_cast<LPVOID*>(&_render)) == MH_OK) {
            MH_EnableHook((void*)renderCtx);
            _logf(L"[TreroInternal]: RenderContext hooked!\n");
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
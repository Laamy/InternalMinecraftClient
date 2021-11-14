#include <windows.h>
#include <MinHook.h>
#include <map>
#include <vector>
#include <Psapi.h>
#include <string>

#define _logf(str)  OutputDebugString(str)

typedef void(__thiscall* chatMsg)(void* a1, class TextHolder* txt);
chatMsg _chatMsg;

// SDK
#include "SDK/Actor.h"
#include "SDK/GuiData.h"
#include "SDK/ClientInstance.h"
#include "SDK/KeyInfo.h"

//KeyInfo* keyinfo;
class ClientInstance* clientInst;

// Utils
#include "Utils/Utils.h"
#include "Utils/RenderUtils.h"

std::vector<class Module*> vMods;

#include "ClientBase/Module.h"

std::map<uint64_t, bool> keymap = std::map<uint64_t, bool>();

#include "ClientBase/ModuleHandler.h"

RenderUtils renderUtil = RenderUtils();
GuiData* acs;
Actor* localPlr;
class BitmapFont* font;
ModuleHandler handler = ModuleHandler();


#define PI 3.14159265359 // 3.14159265359

typedef void(__thiscall* tick)(ClientInstance* clientinstance, void* a2);
tick _tick;

typedef void(__thiscall* player)(Actor* lp, void* a2);
player _player;

typedef void(__thiscall* key)(uint64_t keyId, bool held);
key _key;

typedef void(__thiscall* mouse)(KeyInfo* cls);
mouse _mouse;

typedef void(__thiscall* render)(void* a1, MinecraftUIRenderContext* ctx);
render _render;

std::map<uint64_t, bool> beforeKeymap = std::map<uint64_t, bool>();

std::map<uint64_t, bool> mousemap = std::map<uint64_t, bool>();

std::vector<std::string> categories = std::vector<std::string>();
std::vector<Vector2> categoryPos = std::vector<Vector2>();

std::map<uint64_t, bool> modulesEnabled = std::map<uint64_t, bool>();

bool cancelUiRender = false;
bool renderClickUI = false;
bool justEnabled = true;

int enabledTicks = 0;
int frame = 0;

void keyCallback(uint64_t c, bool v) { // Store key infomation inside our own keymap ;p
    if (c == 0x2D && keymap[c] == false && v == true) {
        renderClickUI = !renderClickUI;
    }

    for (int i = 0; i < handler.modules.size(); ++i) {
        if (handler.modules[i]->keybind == c && modulesEnabled[i] == false && v == true) {

            handler.modules[i]->enabled = !handler.modules[i]->enabled;

            if (handler.modules[i]->enabled)
                handler.modules[i]->OnEnable(clientInst, localPlr);
            else handler.modules[i]->OnDisable(clientInst, localPlr);

        }
    }

    keymap[c] = v;
    _key(c, v);
};

void mouseCallback(KeyInfo* cls) {
    //keyinfo = cls;
    //if (keyinfo->leftMouseDown)
        //_logf(L"MouseDown");
    //_mouse(cls);

};

void tCallback(void* a1, MinecraftUIRenderContext* ctx) {
    if (renderUtil.ctx == nullptr && font != nullptr)
        renderUtil.Init(ctx, acs, font, reinterpret_cast<class Handle*>(&handler));

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

                renderUtil.Draw(
                    Vector2((float)(70 + (cat * 60)), 80),
                    Vector2(48, 10), _RGB(33, 33, 33));

                auto catText = TextHolder(x); // (ctx->getLineLength(font, &catText, 1) / 2)

                renderUtil.DrawString(
                    Vector2(95 + (cat * 60) - (ctx->getLineLength(font, &catText, 0.6f) / 2), 165),
                    _RGB(255, 255, 255),
                    catText, font, 0.6f);

                int catMod = 0;
                for (int i = 0; i < handler.modules.size(); ++i) {
                    if (handler.modules[i]->category == x) {
                        auto moduleBtnInfo = TextHolder(handler.modules[i]->name);
                        auto cda = renderUtil.DrawButtonText(Vector2((float)(70 + (cat * 60)), 90 + (catMod * 10)), Vector2(48, 10), _RGB(55, 55, 55), _RGB(44, 44, 44), _RGB(40, 40, 40), renderUtil.guiData->scaledMousePos(), keymap[(int)' '],
                            moduleBtnInfo, font, 0.6f, Vector2(24 - (ctx->getLineLength(font, &moduleBtnInfo, 0.6f) / 2), 4), handler.modules[i]->enabled);
                        if (cda && keymap[(int)' '] && beforeKeymap[i] == false) {
                            handler.modules[i]->enabled = !handler.modules[i]->enabled;
                            if (!handler.modules[i]->enabled)
                                handler.modules[i]->OnDisable(clientInst, localPlr);
                            else
                                handler.modules[i]->OnEnable(clientInst, localPlr);
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
    //Simple Inject Notification by zPearls, but re-made!!
    if (justEnabled) {
        enabledTicks++;
        if (enabledTicks > 1 && enabledTicks < 1000) {//around 3s //checking if bigger then 1 to make sure no rando crashes appear :P
            auto catText = TextHolder("Trero Internal has been Injected!");
            renderUtil.DrawString(Vector2(300 - (ctx->getLineLength(font, &catText, 0.6f) / 2), 1), _RGB(255, 255, 255), catText, font, 1.0f);
            renderUtil.DrawOutline(Vector2(297 - (ctx->getLineLength(font, &catText, 0.6f) / 2), 0), Vector2(181, 11), _RGB(255, 255, 255), 1.0);
        }
        else if (enabledTicks > 1000) {//this is so the text dissapears btw, same goes for enabledTicks and justEnabled ;/
            justEnabled = false;
            enabledTicks = 0;
        }
    }

    for (int i = 0; i < handler.modules.size(); i++)
        modulesEnabled[i] = handler.modules[i]->enabled;
};

void callback(ClientInstance* ci, void* a2) {

    clientInst = ci;
    acs = ci->guiData;
    font = ci->mcGame->defaultGameFont;

    for (auto mod : handler.modules)
        if (ci->isInGame() && mod->enabled)
            mod->OnTick(ci);

    _tick(ci, a2);
};

void playerCallback(Actor* lp, void* a2) {
    localPlr = lp;
    for (auto mod : handler.modules)
        if (mod->enabled)
            mod->OnGameTick(lp);
    _player(lp, a2);
};

/*void DisplayObj(const char txt[64]) {
    auto sce = TextHolder(txt);
    if (clientInst->guiData != nullptr)
        _chatMsg(&clientInst->guiData, &sce);
}
void SendChatMsg(const char txt[64]) { // i was testing please ignore!
    auto sce = TextHolder(txt);
    //DisplayObj("Sent!");
    _chatMsg(&clientInst->guiData, &sce);
}
void chatMsgCallback(void* a1, TextHolder* txt) { // callback (Maybe i can use this for .commands and cheat around hooking my packet func in lbs?

    //auto cse = TextHolder("[TreroInternal]: ChatMsg Detected!");
    //_chatMsg(a1, &cse);
    if (txt->getText()[0] != '.') // cancel all .command related chat msgs :p
        _chatMsg(a1, txt);
    //else SendChatMsg("Cancelled command!");
};*/

void Init(HMODULE c) {
    if (MH_Initialize() == MH_OK) {

        handler.InitModules();

        vMods = handler.modules;

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
        // uintptr_t ImmobileAddr = Mem::findSig("40 53 48 83 EC ? 48 8B D9 E8 ? ? ? ? 84 C0 75 ? 48 8B 03 48 8B CB"); could be used in future
        uintptr_t hookAddr = Mem::findSig("48 8B 01 48 8D 54 24 ? FF 90 ? ? ? ? 90 48 8B 08 48 85 ? 0F 84 ? ? ? ? 48 8B 58 08 48 85 DB 74 0B F0 FF 43 08 48 8B 08 48 8B 58 08 48 89 4C 24 20 48 89 5C 24 28 48 8B 09 48 8B 01 4C 8B C7 48 8B");
        uintptr_t localPlayerAddr = Mem::findSig("F3 0F 10 81 ? ? ? ? 41 0F 2F 00"); //VV - 83 7B 4C 01 75 1C 80 7B
        //uintptr_t displayObjAddr = Mem::findSig("48 89 5C 24 ? 48 89 74 24 ? 55 57 41 54 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 30 4C 8B F1");
        //uintptr_t mouseAddr = Mem::findSig("48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 55 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 F0 48 8B ? E8");
        uintptr_t renderCtxAddr = Mem::findSig("48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B FA 48 89 54 24 ? 4C 8B");
        //uintptr_t chatMsgSigAddr = Mem::findSig("48 89 5C 24 ?? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ?? ?? ?? ?? 48 81 EC ?? ?? ?? ?? 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 85 ?? ?? ?? ?? 4C 8B EA 4C 8B F9 48 8B 49");

        _logf(L"[TreroInternal]: Hooking functions...\n");

        /*if (MH_CreateHook((void*)chatMsgSigAddr, &chatMsgCallback, reinterpret_cast<LPVOID*>(&_chatMsg)) == MH_OK) {
            MH_EnableHook((void*)chatMsgSigAddr);
            _logf(L"[TreroInternal]: ChatMsg hooked!\n");
            SendChatMsg("[TreroInternal]: ChatMsg hooked!");
        };*/

        if (MH_CreateHook((void*)keymapAddr, &keyCallback, reinterpret_cast<LPVOID*>(&_key)) == MH_OK) {
            MH_EnableHook((void*)keymapAddr);
            //memcpy((void*)keymapAddr, copy.inlineText, 0x1000);
            _logf(L"[TreroInternal]: Keymap hooked!\n");
            //SendChatMsg("[TreroInternal]: Keymap hooked!");
        };
        if (MH_CreateHook((void*)hookAddr, &callback, reinterpret_cast<LPVOID*>(&_tick)) == MH_OK) {
            MH_EnableHook((void*)hookAddr);
            _logf(L"[TreroInternal]: ClientInstance hooked!\n");
            // SendChatMsg("[TreroInternal]: ClientInstance hooked!");
        };
        if (MH_CreateHook((void*)localPlayerAddr, &playerCallback, reinterpret_cast<LPVOID*>(&_player)) == MH_OK) {
            MH_EnableHook((void*)localPlayerAddr);
            _logf(L"[TreroInternal]: LocalPlayer hooked!\n");
            //SendChatMsg("[TreroInternal]: LocalPlayer hooked!");
        };
        //if (MH_CreateHook((void*)mouseAddr, &mouseCallback, reinterpret_cast<LPVOID*>(&_mouse)) == MH_OK) {
        //    MH_EnableHook((void*)mouseAddr);
        //    _logf(L"[TreroInternal]: KeyInfo hooked!\n");
        //};
        if (MH_CreateHook((void*)renderCtxAddr, &tCallback, reinterpret_cast<LPVOID*>(&_render)) == MH_OK) {
            MH_EnableHook((void*)renderCtxAddr);
            _logf(L"[TreroInternal]: RenderContext hooked!\n");
            //SendChatMsg("[TreroInternal]: RenderContext hooked!");
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
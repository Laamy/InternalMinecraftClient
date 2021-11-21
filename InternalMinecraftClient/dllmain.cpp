#include <windows.h>
#include <MinHook.h>
#include <map>
#include <vector>
#include <Psapi.h>
#include <string>

#include <cassert>

#define _logf(str)  OutputDebugString(str)

typedef void(__thiscall* chatMsg)(void* a1, class TextHolder* txt);
chatMsg _chatMsg;

std::map<uint64_t, class Actor*> entityList = std::map<uint64_t, class Actor*>(); // 1.17.41 entitylist

bool clientAlive = true;

// SDK
#include "SDK/Actor.h"
#include "SDK/Player.h"
#include "SDK/GuiData.h"
#include "SDK/ClientInstance.h"
#include "SDK/KeyInfo.h"

//KeyInfo* keyinfo;
class ClientInstance* clientInst;

// Utils
#include "Utils/Utils.h"
#include "Utils/RenderUtils.h"

std::vector<class Module*> vMods;

#include "ClientBase/Command.h"
#include "ClientBase/Module.h"

std::map<uint64_t, bool> keymap = std::map<uint64_t, bool>();

#include "ClientBase/ModuleHandler.h"
#include "ClientBase/CommandHandler.h"

RenderUtils renderUtil = RenderUtils();
GuiData* acs;
Actor* localPlr;
class BitmapFont* font;
ModuleHandler handler = ModuleHandler();
CommandHandler cmdHandler = CommandHandler();

#define PI 3.14159265359 // 3.14159265359

typedef void(__thiscall* tick)(ClientInstance* clientinstance, void* a2);
tick _tick;

typedef void(__thiscall* player)(Actor* lp, void* a2);
player _player;

typedef void(__thiscall* key)(uint64_t keyId, bool held);
key _key;

typedef void(__thiscall* blockRenderer)(void* rendercls, void* block); // rendercls never changes block is the current block that is being rendered via this func
blockRenderer _renderBlock;

typedef bool(__thiscall* Immobile)(Actor* lp);
Immobile _Immobile;

typedef float(__thiscall* time)(__int64 a1, int a2, float a3);
time _time;

typedef bool(__thiscall* test)(__int64 _this, float* color, __int64 a3, float a4);
test _Test;

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
bool justDisabled = false;

int disabledTicks = 0;
int enabledTicks = 0;
int frame = 0;

void keyCallback(uint64_t c, bool v) { // Store key infomation inside our own keymap ;p
    _key(c, v);

    if (c == VK_INSERT && keymap[c] == false && v == true) {
        renderClickUI = !renderClickUI;
    }

    for (int i = 0; i < handler.modules.size(); ++i) {
        if (c == handler.modules[i]->keybind && handler.modules[i]->HoldMode()) {
            handler.modules[i]->enabled = !handler.modules[i]->enabled;

            if (handler.modules[i]->enabled)
                handler.modules[i]->OnEnable(clientInst, localPlr);
            else handler.modules[i]->OnDisable(clientInst, localPlr);

        }else if (!handler.modules[i]->HoldMode() && c == handler.modules[i]->keybind && v == true) {
            handler.modules[i]->enabled = !handler.modules[i]->enabled;

            if (handler.modules[i]->enabled)
                handler.modules[i]->OnEnable(clientInst, localPlr);
            else handler.modules[i]->OnDisable(clientInst, localPlr);

        }
    }

    keymap[c] = v;
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
        if (enabledTicks > 1 && enabledTicks < 3000) {//around 3s //checking if bigger then 1 to make sure no rando crashes appear :P
            auto Text = TextHolder("Trero Internal has been Injected!");

            int alpha = 255; // make injection notification fade :p ( yaami<3#8483 )
            if (enabledTicks <= 400)
                alpha += enabledTicks - 400;
            else if (enabledTicks >= 745)
                alpha -= enabledTicks - 745;

            renderUtil.DrawString(Vector2(300 - (ctx->getLineLength(font, &Text, 0.6f) / 2), 1), _RGB(255, 255, 255, alpha), Text, font);
            renderUtil.DrawOutline(Vector2(297 - (ctx->getLineLength(font, &Text, 0.6f) / 2), 0), Vector2(181, 11), _RGB(255, 255, 255, alpha)); // some reason not drawing the outline :/
        }
        else if (enabledTicks > 1000) {//this is so the text dissapears btw, same goes for enabledTicks and justEnabled ;/
            justEnabled = false;
            enabledTicks = 0;
        }
    }

    for (int i = 0; i < handler.modules.size(); i++)
        modulesEnabled[i] = handler.modules[i]->enabled;

    for (auto mod : handler.modules) {
        auto Eject = mod->name == "Uninject";
        if (Eject && mod->enabled)
            clientAlive = false;
    }
    if (keymap[VK_CONTROL] && keymap['L']) { // YO WHOI ADDED TGUIS TY!
        clientAlive = false;
    }
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
    _player(lp, a2);

    entityList[reinterpret_cast<uint64_t>(lp)] = lp;

    localPlr = lp;
    for (auto mod : handler.modules)
        if (mod->enabled)
            mod->OnGameTick(lp);
};

void renderBlockCallback(void* cls, void* block) { // Runs 0x10(16) times per game frame
   /*for (auto mod : handler.modules) {
        auto test = mod->name == "ChestRay";
        if (test && mod->enabled) {
            return;
        }
    }*/
    _renderBlock(cls, block);
};

bool MobImmobile(Actor* lp) {
    for (auto mod : handler.modules) {
        auto test = mod->name == "AntiImmobile";
        if (test && mod->enabled) { // there has to be a better way to do this
            return false;
        }
    }
    return _Immobile(lp);
};

bool Test(__int64 _this, float* color, __int64 a3, float a4) { // There is - Yaami.
    // Initialize these hooks in the module constructor {};
    // I'll preplace the comment for where you need to place this hook code

    for (auto mod : handler.modules) {
        auto test = mod->name == "TestModule";
        if (test && mod->enabled) {
            return 0;// there has to be a better way to do this
        }
    }
    return _Test(_this, color, a3, a4);
};


float timeOfDay(__int64 a1, int a2, float a3) {
    // Initialize these hooks in the module constructor {};
    // I'll preplace the comment for where you need to place this hook code

    for (auto mod : handler.modules) {
        auto test = mod->name == "TestModule";
        if (test && mod->enabled) {
           return 121000.f;
        }
        else {
            return _time(a1, a3, a3);
        }
    }
};

void SendChatMsg(const char txt[64]) { // i was testing please ignore!
    auto sce = TextHolder(txt);
    //DisplayObj("Sent!");
    //_chatMsg(&clientInst->guiData, &sce);
}

void DisplayObj(const char txt[64]) {
    auto sce = TextHolder(txt);
    if (clientInst->guiData != nullptr)
        _chatMsg(&clientInst->guiData, &sce);
}

void chatMsgCallback(void* a1, TextHolder* txt) { // callback (Maybe i can use this for .commands and cheat around hooking my packet func in lbs?)
  
    if (txt->getText()) {
        auto command = ((std::string)txt->getText()).erase(0,0);
        if (command == "dad?") {
            auto cse = TextHolder("[TreroInternal]: Im getting Milk!!!!");
            _chatMsg(a1, &cse);
        }
        if (command == "mom?") {
            auto cse = TextHolder("[TreroInternal]: Yes My Child????");
            _chatMsg(a1, &cse);
        }
    }else _chatMsg(a1, txt);


    for (auto mod : handler.modules) {
        auto test = mod->name == "Spammer";
        if (test && mod->enabled) { // there has to be a better way to do this - (std::map is the better way)
            for (int i = 0; i < 10; i++)
                _chatMsg(a1, txt);
        }
    }

    if (txt->getText()[0] == '.') { // cancel all .command related chat msgs :p
        auto command = ((std::string)txt->getText()).erase(0, 1);
        auto command = ((std::string)txt->getText()).erase(0, 1);
        Command* checkCmd = cmdHandler.findCommand(command);
        if (checkCmd != nullptr) {
            checkCmd->Execute(clientInst, localPlr);
        }
        if (command == "eject" || command == "uninject") {
            clientAlive = false;
        }

        if (command == "toggle") {
            for (auto mod : handler.modules) {
                if (mod->enabled) {
                    if (mod->name == "TestModule") {
                        mod->enabled = false;
                    }
                }
                else {
                    if (mod->name == "TestModule") {
                        mod->enabled = true;
                    }
                }
            }
        }
    }
    else {
        _chatMsg(a1, txt);
    }
};//ill make commands work like modules/well sorted later -> zPearlss

std::string getClipboardText() {
    if (!OpenClipboard(nullptr)) {
        return "";
    }
    else {
        HANDLE hData = GetClipboardData(CF_TEXT);
        char* pszText = static_cast<char*>(GlobalLock(hData));
        if (pszText == nullptr)
            return "";
        CloseClipboard();
        return std::string(pszText);
    }
}

void setClipboardText(std::string text) {
    if (!OpenClipboard(nullptr))
        return;
    EmptyClipboard();
    HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, text.size() + 1);
    if (!hg) {
        CloseClipboard();
        return;
    }
    memcpy(GlobalLock(hg), text.c_str(), text.size() + 1);
    GlobalUnlock(hg);
    SetClipboardData(CF_TEXT, hg);
    CloseClipboard();
    GlobalFree(hg);
}

auto GetDllHMod(void) -> HMODULE {
    MEMORY_BASIC_INFORMATION info;
    size_t len = VirtualQueryEx(GetCurrentProcess(), (void*)GetDllHMod, &info, sizeof(info));
    assert(len == sizeof(info));
    return len ? (HMODULE)info.AllocationBase : NULL;
};

void Init(LPVOID c) {
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
        uintptr_t testAddr = Mem::findSig("41 0F 10 08 48 8B C2 0F"); // fog color
        uintptr_t timeOfDayAddr = Mem::findSig("44 8B C2 B8 F1 19 76 05 F7 EA");
        uintptr_t hookAddr = Mem::findSig("48 8B 01 48 8D 54 24 ? FF 90 ? ? ? ? 90 48 8B 08 48 85 ? 0F 84 ? ? ? ? 48 8B 58 08 48 85 DB 74 0B F0 FF 43 08 48 8B 08 48 8B 58 08 48 89 4C 24 20 48 89 5C 24 28 48 8B 09 48 8B 01 4C 8B C7 48 8B");
        uintptr_t localPlayerAddr = Mem::findSig("F3 0F 10 81 ? ? ? ? 41 0F 2F 00"); //VV - 83 7B 4C 01 75 1C 80 7B
        //uintptr_t displayObjAddr = Mem::findSig("48 89 5C 24 ? 48 89 74 24 ? 55 57 41 54 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 30 4C 8B F1");
        //uintptr_t mouseAddr = Mem::findSig("48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 55 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 F0 48 8B ? E8");
        uintptr_t ImmobileAddr = Mem::findSig("48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 30 48 8D 54 24 20 E8 A7 EC FA FE 90 48 8B C8 E8 8E 53 98 FE 48 8B D8 48 8B C8 E8 B3 FA 11 00 84 C0 75 15"); //when the intop is smart :Flushed:
        uintptr_t renderCtxAddr = Mem::findSig("48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B FA 48 89 54 24 ? 4C 8B");
        uintptr_t chatMsgSigAddr = Mem::findSig("48 89 5C 24 ?? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ?? ?? ?? ?? 48 81 EC ?? ?? ?? ?? 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 85 ?? ?? ?? ?? 4C 8B EA 4C 8B F9 48 8B 49");
        uintptr_t blockRendererAddr = Mem::findSig("48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 4C 89 4C");

        _logf(L"[TreroInternal]: Hooking functions...\n");

        if (MH_CreateHook((void*)chatMsgSigAddr, &chatMsgCallback, reinterpret_cast<LPVOID*>(&_chatMsg)) == MH_OK) {
            MH_EnableHook((void*)chatMsgSigAddr);
            _logf(L"[TreroInternal]: ChatMsg hooked!\n");
        };

        if (MH_CreateHook((void*)blockRendererAddr, &renderBlockCallback, reinterpret_cast<LPVOID*>(&_renderBlock)) == MH_OK) {
            MH_EnableHook((void*)blockRendererAddr);
            _logf(L"[TreroInternal]: BlockRenderer hooked!\n");
        };

        if (MH_CreateHook((void*)ImmobileAddr, &MobImmobile, reinterpret_cast<LPVOID*>(&_Immobile)) == MH_OK) {
            MH_EnableHook((void*)ImmobileAddr);
            _logf(L"[TreroInternal]: Immobile hooked!\n");
        };

        if (MH_CreateHook((void*)timeOfDayAddr, &timeOfDay, reinterpret_cast<LPVOID*>(&_time)) == MH_OK) {
            MH_EnableHook((void*)timeOfDayAddr);
            _logf(L"[TreroInternal]: TimeOfDay hooked!\n");
        };

        if (MH_CreateHook((void*)testAddr, &Test, reinterpret_cast<LPVOID*>(&_Test)) == MH_OK) {
            MH_EnableHook((void*)testAddr);
            _logf(L"[TreroInternal]: Test hooked!\n");
        };

        if (MH_CreateHook((void*)keymapAddr, &keyCallback, reinterpret_cast<LPVOID*>(&_key)) == MH_OK) {
            MH_EnableHook((void*)keymapAddr);
            //memcpy((void*)keymapAddr, copy.inlineText, 0x1000);
            _logf(L"[TreroInternal]: Keymap hooked!\n");
        };
        if (MH_CreateHook((void*)hookAddr, &callback, reinterpret_cast<LPVOID*>(&_tick)) == MH_OK) {
            MH_EnableHook((void*)hookAddr);
            _logf(L"[TreroInternal]: ClientInstance hooked!\n");
        };
        if (MH_CreateHook((void*)localPlayerAddr, &playerCallback, reinterpret_cast<LPVOID*>(&_player)) == MH_OK) {
            MH_EnableHook((void*)localPlayerAddr);
            _logf(L"[TreroInternal]: LocalPlayer hooked!\n");
        };
        //if (MH_CreateHook((void*)mouseAddr, &mouseCallback, reinterpret_cast<LPVOID*>(&_mouse)) == MH_OK) {
        //    MH_EnableHook((void*)mouseAddr);
        //    _logf(L"[TreroInternal]: KeyInfo hooked!\n");
        //};
        if (MH_CreateHook((void*)renderCtxAddr, &tCallback, reinterpret_cast<LPVOID*>(&_render)) == MH_OK) {
            MH_EnableHook((void*)renderCtxAddr);
            _logf(L"[TreroInternal]: RenderContext hooked!\n");
        };

    lab:
        while (clientAlive) {};
        Sleep(1);

        if (clientAlive)
            goto lab;

        MH_DisableHook(MH_ALL_HOOKS);
        FreeLibraryAndExitThread(GetDllHMod(), 0);
    };
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Init, hModule, 0, 0);
    }
    return TRUE;
}

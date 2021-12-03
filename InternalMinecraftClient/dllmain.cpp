#include <windows.h>
#include <MinHook.h>
#include <map>
#include <vector>
#include <Psapi.h>
#include <string>
#include <cassert>
// Memory
#include "Memory/GameHooks.h"
BaseClient* hooks = new BaseClient();
#define _logf(str)  OutputDebugString(str)
typedef void(__thiscall* chatMsg)(void* a1, class TextHolder* txt);
chatMsg _chatMsg;
bool cancelUiRender = false;
auto GetDllHMod(void) -> HMODULE {
    MEMORY_BASIC_INFORMATION info;
    size_t len = VirtualQueryEx(GetCurrentProcess(), (void*)GetDllHMod, &info, sizeof(info));
    assert(len == sizeof(info));
    return len ? (HMODULE)info.AllocationBase : NULL;
}

std::map<uint64_t, class Actor*> entityList = std::map<uint64_t, class Actor*>(); // 1.17.41 entitylist
std::map<uint64_t, class Actor*> completeEntityList = std::map<uint64_t, class Actor*>();

bool clientAlive = true;

class BitmapFont* font;

// SDK
#include "SDK/Actor.h"
#include "SDK/Player.h"
#include "SDK/GuiData.h"
#include "SDK/GLMatrix.h"
#include "SDK/LevelRender.h"
#include "SDK/ClientInstance.h"
#include "SDK/KeyInfo.h"

//KeyInfo* keyinfo;
class ClientInstance* clientInst;

// Utils
#include "Utils/Utils.h"
#include "Utils/RenderUtils.h"
#include "Utils/VisualElement.h"

RenderUtils renderUtil = RenderUtils();

std::vector<class Command*> vCmds;
std::vector<class Module*> vMods;
#include "ClientBase/Command.h"
#include "ClientBase/Module.h"

std::map<uint64_t, bool> keymap = std::map<uint64_t, bool>();
#include "ClientBase/ModuleHandler.h"
#include "ClientBase/CommandHandler.h"

GuiData* acs;
Actor* localPlr;
ModuleHandler handler = ModuleHandler();
CommandHandler cmdHandler = CommandHandler();

#define PI 3.14159265359 // 3.14159265359
typedef void(__thiscall* tick)(ClientInstance* clientinstance, void* a2);
tick _tick;
typedef void(__thiscall* player)(Actor* lp, void* a2);
player _player;
typedef void(__thiscall* gamemode)(GameMode* gm, void* a2);
gamemode _gamemode;
typedef void(__thiscall* key)(uint64_t keyId, bool held);
key _key;
typedef void(__thiscall* render)(void* a1, MinecraftUIRenderContext* ctx);
render _render;
std::map<uint64_t, bool> beforeKeymap = std::map<uint64_t, bool>();
std::map<uint64_t, bool> mousemap = std::map<uint64_t, bool>();
std::vector<std::string> categories = std::vector<std::string>();
std::vector<Vector2> categoryPos = std::vector<Vector2>();
std::map<uint64_t, bool> modulesEnabled = std::map<uint64_t, bool>();

bool renderClickUI = false;
bool justEnabled = true;
bool justDisabled = false;
int disabledTicks = 0;
int enabledTicks = 0;
int frame = 0;
//Hopefully could be used
KeyInfo* mouse;
bool isRightClickDown() {
    if (mouse == 0)
        return false;
    return mouse->rightClickDown;
}

bool isLeftClickDown() {
    if (mouse == 0)
        return false;
    return mouse->leftClickDown;
}

bool isWheelDown() {
    if (mouse == 0)
        return false;
    return mouse->wheelDown;
}

void keyCallback(uint64_t c, bool v) { // Store key infomation inside our own keymap ;p
    _key(c, v);
    if (c == VK_INSERT && keymap[c] == false && v == true) {
        renderClickUI = !renderClickUI;
        if (renderClickUI)
            clientInst->grabMouse();
        else clientInst->releaseMouse();
    }

    for (int i = 0; i < handler.modules.size(); ++i) {
        if (!renderClickUI) {
            if (c == handler.modules[i]->keybind && handler.modules[i]->HoldMode()) {//for modules like jetpack
                handler.modules[i]->enabled = !handler.modules[i]->enabled;
                if (handler.modules[i]->enabled)
                    handler.modules[i]->OnEnable(clientInst, localPlr);
                else handler.modules[i]->OnDisable(clientInst, localPlr);
            } else if (!handler.modules[i]->HoldMode() && c == handler.modules[i]->keybind && v == true) {//for normal modules
                handler.modules[i]->enabled = !handler.modules[i]->enabled;
                if (handler.modules[i]->enabled) {
                    handler.modules[i]->OnEnable(clientInst, localPlr);
                    for (auto mod : handler.modules) {
                        auto Notis = mod->name == "Notifications";
                        if (Notis && mod->enabled)
                            hooks->debugEcho("ModuleEnabled", "Module has been enabled");
                    }
                } else {
                    handler.modules[i]->OnDisable(clientInst, localPlr);
                    for (auto mod : handler.modules) {
                        auto Notis = mod->name == "Notifications";
                        if (Notis && mod->enabled)
                            hooks->debugEcho("ModuleDisabled", "Module has been disabled");
                    }
                }
            }
        }
    }
    keymap[c] = v;
}

void tCallback(void* a1, MinecraftUIRenderContext* ctx) { // RenderContext
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
            float cat = 0;
            for (std::string x : categories) {
                renderUtil.Draw(Vector2((float)(70 + (cat * 60)), 80), Vector2(75, 10), _RGB(33, 33, 33));
                auto catText = TextHolder(x); // (ctx->getLineLength(font, &catText, 1) / 2)
                renderUtil.DrawString(Vector2(80 + (cat * 60) - (ctx->getLineLength(font, &catText, 0.6f) / 2), 80), _RGB(255, 255, 255), catText, font, 1.f);
                int catMod = 0;
                for (int i = 0; i < handler.modules.size(); ++i) {
                    if (handler.modules[i]->category == x) {
                        auto modInstance = handler.modules[i];
                        auto moduleBtnInfo = TextHolder(modInstance->name);
                        auto cda = renderUtil.DrawButtonText(Vector2((float)(70.f + (cat * 60.f)), 90.f + (catMod * 10.f)), Vector2(75.f, 10.f), _RGB(55, 55, 55), _RGB(44, 44, 44), _RGB(40, 40, 40), renderUtil.guiData->scaledMousePos(), keymap[(int)' '],
                            moduleBtnInfo, font, 0.6f, Vector2(24 - (ctx->getLineLength(font, &moduleBtnInfo, 0.6f) / 2), 4), handler.modules[i]->enabled, modInstance->vElement);
                        if (cda) {
                            handler.modules[i]->drawTooltip(TextHolder(handler.modules[i]->tooltip));
                            //hooks->debugEcho("Tooltip", "Tooltips in use");
                        }                            

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
                cat += 1.5f;
            }
        }
        frame = 0;
    }

    int loopIndex = 0;
    for (auto notification : hooks->notifications) {
        notification->existedTick++;
        if (notification->existedTick == notification->canExistFor/*Tick*/)
            hooks->notifications.erase(std::remove(hooks->notifications.begin(), hooks->notifications.end(), notification),
                hooks->notifications.end());
        if (notification->existedTick >= (notification->canExistFor - 255)/*Tick*/)
            notification->fadeAlpha--; // make notification fade out
        if (notification->existedTick <= 255/*Tick*/)
            notification->fadeAlpha++; // make notification fade in
        // Render The Notification
        renderUtil.DrawString(Vector2(25.f, 25.f + (20.f/*textSize*/ * loopIndex)), _RGB(255, 255, 255, (int)notification->fadeAlpha), TextHolder(notification->notificationDesc), font, 0.8f);
        loopIndex++;
    }

    for (int i = 0; i < handler.modules.size(); i++)
        modulesEnabled[i] = handler.modules[i]->enabled;

    if (justDisabled && clientInst->isInGame()) { //Eject Message
        disabledTicks++;
        if (disabledTicks == 1) {
            localPlr->displayClientMessage("[TreroInternal] Client succesfuly ejected!");
        }
    }

    for (auto mod : handler.modules) {
        auto Eject = mod->name == "Uninject";
        if (Eject && mod->enabled || keymap[VK_CONTROL] && keymap['L']) {
            justDisabled = true;
            clientAlive = false;
        }
    }
}

void callback(ClientInstance* ci, void* a2) {
    clientInst = ci; acs = ci->getGuiData();
    font = ci->mcGame->defaultGameFont;
    for (auto mod : handler.modules)
    if (ci->isInGame() && mod->enabled)
    mod->OnTick(ci); _tick(ci, a2);
}

int a = 0;

void playerCallback(Actor* lp, void* a2) {
    _player(lp, a2);
    if (lp->isLocalPlayer()) {
        localPlr = lp;
    }
    entityList[reinterpret_cast<uint64_t>(lp)] = lp;
    for (auto mod:handler.modules)
    if (mod->enabled) mod->OnGameTick(lp);
}
/*
void gamemodeCallback(GameMode* gm, void* a2) {
    _gamemode(gm, a2);
    for (auto mod : handler.modules)
    if (mod->enabled) mod->OnGameTick(gm);
}
*/
void SendChatMsg(const char txt[64]) { // i was testing please ignore!
    auto sce = TextHolder(txt);
    //DisplayObj("Sent!");
    //_chatMsg(&clientInst->guiData, &sce);
}

void DisplayObj(const char txt[64]) {
    auto sce = TextHolder(txt);
    if (clientInst->getGuiData() != nullptr)
        _chatMsg(clientInst->getGuiData(), &sce);
}

std::vector<std::string> split(const std::string& text, char sep) {
    std::vector<std::string> tokens;
    std::size_t start = 0, end = 0;
    while ((end = text.find(sep, start)) != std::string::npos) {
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(text.substr(start));
    return tokens;
}

void chatMsgCallback(void* a1, TextHolder* txt) {
    for (auto mod : handler.modules) {
        auto test = mod->name == "Spammer";
        if (test && mod->enabled) { //(std::map is the better way)
            for (int i = 0; i < 10; i++)
                _chatMsg(a1, txt);
        }
    }
    if (txt->getText()[0] == '.') { // cancel all .command related chat msgs :p
        auto command = ((std::string)txt->getText()).erase(0, 1);
        Command* checkCmd = cmdHandler.findCommand(command);
        if (checkCmd != nullptr) {
            auto txt2 = ((std::string)txt->getText());
            checkCmd->Execute(split(txt2, ' '));
        }
    } else _chatMsg(a1, txt);
}

std::string getClipboardText() {
    if (!OpenClipboard(nullptr))
        return "";
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

void Init(LPVOID c) {
    if (MH_Initialize() == MH_OK) {
        handler.InitModules();
        cmdHandler.InitCommands();
        vMods = handler.modules;
        for (auto mod : handler.modules) {
            bool addCategory = true;
            for (auto cat : categories)
            if (mod->category == cat) addCategory = false;
            if (addCategory)
            categories.push_back(mod->category);
        }
        // Function hooks
        uintptr_t keymapAddr = Mem::findSig("48 89 5C 24 08 57 48 83 EC ? 8B 05 ? ? ? ? 8B DA 89");
        uintptr_t hookAddr = Mem::findSig("48 8B 01 48 8D 54 24 ? FF 90 ? ? ? ? 90 48 8B 08 48 85 ? 0F 84 ? ? ? ? 48 8B 58 08 48 85 DB 74 0B F0 FF 43 08 48 8B 08 48 8B 58 08 48 89 4C 24 20 48 89 5C 24 28 48 8B 09 48 8B 01 4C 8B C7 48 8B");
        uintptr_t localPlayerAddr = Mem::findSig("F3 0F 10 81 ? ? ? ? 41 0F 2F 00"); //VV - 83 7B 4C 01 75 1C 80 7B
        //uintptr_t gamemodeAddr = Mem::findSig("48 8D 05 02 80 23 02 48 89 01 48 89 51 08 48 C7 41 10 FF FF FF FF C7 41 18 FF FF FF FF 44 88 61 1C");
        //uintptr_t displayObjAddr = Mem::findSig("48 89 5C 24 ? 48 89 74 24 ? 55 57 41 54 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 30 4C 8B F1");
        //uintptr_t mouseAddr = Mem::findSig("48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 55 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 F0 48 8B ? E8");
        uintptr_t renderCtxAddr = Mem::findSig("48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B FA 48 89 54 24 ? 4C 8B"); //48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B FA 48 89 54 24 ? 4C 8B
        uintptr_t chatMsgSigAddr = Mem::findSig("48 89 5C 24 ?? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ?? ?? ?? ?? 48 81 EC ?? ?? ?? ?? 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 85 ?? ?? ?? ?? 4C 8B EA 4C 8B F9 48 8B 49");
        _logf(L"[TreroInternal]: Hooking functions...\n");
        if (MH_CreateHook((void*)chatMsgSigAddr, &chatMsgCallback, reinterpret_cast<LPVOID*>(&_chatMsg)) == MH_OK) {
            MH_EnableHook((void*)chatMsgSigAddr);
            _logf(L"[TreroInternal]: ChatMsg hooked!\n");
        };
        if (MH_CreateHook((void*)keymapAddr, &keyCallback, reinterpret_cast<LPVOID*>(&_key)) == MH_OK) {
            MH_EnableHook((void*)keymapAddr);
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
       /*if (MH_CreateHook((void*)gamemodeAddr, &gamemodeCallback, reinterpret_cast<LPVOID*>(&_gamemode)) == MH_OK) {
            MH_EnableHook((void*)gamemodeAddr);
            _logf(L"[TreroInternal]: GameMode hooked!\n");
        };*/
        //if (MH_CreateHook((void*)mouseAddr, &mouseCallback, reinterpret_cast<LPVOID*>(&_mouse)) == MH_OK) {
        //    MH_EnableHook((void*)mouseAddr);
        //    _logf(L"[TreroInternal]: KeyInfo hooked!\n");
        //};
        if (MH_CreateHook((void*)renderCtxAddr, &tCallback, reinterpret_cast<LPVOID*>(&_render)) == MH_OK) {
            MH_EnableHook((void*)renderCtxAddr);
            _logf(L"[TreroInternal]: RenderContext hooked!\n");
        };
        hooks->debugEcho("InitMsg", "Client has initialized");

    lab:
        while (clientAlive) {};
        Sleep(1);
        if (clientAlive)
        goto lab;
        MH_DisableHook(MH_ALL_HOOKS);
        MH_RemoveHook(MH_ALL_HOOKS);
        FreeLibraryAndExitThread(GetDllHMod(), 0);
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Init, hModule, 0, 0);
    }
    return TRUE;
}
#include <windows.h>
#include <vector>
#include "Module.h"

class ModuleHandler {
public:
    static std::vector<Module> modules;

public:
    static void InitModules() {
        _logf(L"[TreroInternal]: Registering modules...\n");

        modules.push_back(Module("Debug", "TestModule", (int)'R'));

        _logf(L"[TreroInternal]: Registered modules!\n");
    }

    static bool* Tick(ClientInstance* ci) {
        bool cancel = false;
        for (Module mod : modules)
            mod.OnTick(ci, &cancel);
        return &cancel;
    }

    static void GameTick(Actor* lp) {
        bool cancel = false;
        for (Module mod : modules)
            mod.OnGameTick(lp, &cancel);
        //return &cancel;
    }

    static bool* FrameRender(RenderUtils* ctx, GuiData* guiDat) {
        bool cancel = false;
        for (Module mod : modules)
            mod.OnFrameRender(ctx, guiDat, &cancel);
        return &cancel;
    }

    static bool* KeyDown(uintptr_t keyId) {
        bool cancel = false;
        for (Module mod : modules)
            mod.OnKeyDown(keyId, &cancel);
        return &cancel;
    }

    static bool* KeyUp(uintptr_t keyId) {
        bool cancel = false;
        for (Module mod : modules)
            mod.OnKeyUp(keyId, &cancel);
        return &cancel;
    }

    static bool* KeyHeld(uintptr_t keyId) {
        bool cancel = false;
        for (Module mod : modules)
            mod.OnKeyHeld(keyId, &cancel);
        return &cancel;
    }
};
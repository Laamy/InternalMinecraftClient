#include "Modules/AirJump.h"
#include "Modules/TestModule.h"
#include "Modules/Watermark.h"

class ModuleHandler {
public:
    std::vector<Module> modules;

public:
    void InitModules() {
        _logf(L"[TreroInternal]: Registering modules...\n");

        modules.push_back(AirJump("Debug"));
        modules.push_back(TestModule("Debug"));

        modules.push_back(Watermark("Visual"));

        _logf(L"[TreroInternal]: Registered modules!\n");
    }

    bool* FrameRender(RenderUtils* ctx, GuiData* guiDat) {
        bool cancel = false;
        for (Module mod : modules)
            if (mod.enabled)
                mod.OnFrameRender(ctx, guiDat, &cancel);
        return &cancel;
    }

    bool* KeyDown(uintptr_t keyId) {
        bool cancel = false;
        for (Module mod : modules)
            if (mod.enabled)
                mod.OnKeyDown(keyId, &cancel);
        return &cancel;
    }

    bool* KeyUp(uintptr_t keyId) {
        bool cancel = false;
        for (Module mod : modules)
            if (mod.enabled)
                mod.OnKeyUp(keyId, &cancel);
        return &cancel;
    }

    bool* KeyHeld(uintptr_t keyId) {
        bool cancel = false;
        for (Module mod : modules)
            if (mod.enabled)
                mod.OnKeyHeld(keyId, &cancel);
        return &cancel;
    }
};
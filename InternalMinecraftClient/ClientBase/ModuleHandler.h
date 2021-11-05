#pragma once

#include "Modules/AirJump.h"
#include "Modules/TestModule.h"
#include "Modules/Watermark.h"

class ModuleHandler {
public:
    std::vector<Module*> modules;

public:
    void InitModules() {
        _logf(L"[TreroInternal]: Registering modules...\n");

        modules.push_back(new AirJump("Debug"));
        modules.push_back(new TestModule("Debug"));

        modules.push_back(new Watermark("Visual"));

        _logf(L"[TreroInternal]: Registered modules!\n");
    }

    void FrameRender(RenderUtils* ctx, GuiData* guiDat) {
        for (auto mod : modules)
            if (mod->enabled) {
                mod->OnFrameRender(ctx, guiDat);
            }
    }
};
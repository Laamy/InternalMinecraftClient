#pragma once

#include <algorithm>

#define PI 3.14159265359 // 3.14159265359

#include "Modules/AirJump.h"
#include "Modules/TestModule.h"
#include "Modules/DebugCursor.h"
#include "Modules/Watermark.h"
#include "Modules/AirStuck.h"
#include "Modules/AutoWalk.h"
#include "Modules/OGMFlight.h"
#include "Modules/ExpandScreen.h"
#include "Modules/FastWater.h"
#include "Modules/Glide.h"
#include "Modules/HighJump.h"
#include "Modules/Zoom.h"
#include "Modules/NoSwing.h"
#include "Modules/Freelook.h"
#include "Modules/Antibot.h"
#include "Modules/NoPacket.h"
#include "Modules/Timer.h"
#include "Modules/Noclip.h"
#include "Modules/Phase.h"
#include "Modules/Step.h"
#include "Modules/Killgame.h"
#include "Modules/Freecam.h"
#include "Modules/ReverseStep.h"
#include "Modules/ArrayList.h"
#include "Modules/Blink.h"
#include "Modules/Spider.h"
#include "Modules/Jesus.h"
#include "Modules/CreativeFly.h"
#include "Modules/DebugMenu.h"
#include "Modules/NoFall.h"
#include "Modules/LifeboatFly.h"
#include "Modules/NoYFlight.h"
#include "Modules/Bhop.h"
#include "Modules/Jetpack.h"
#include "Modules/Criticals.h"
#include "Modules/AntiVoid.h"

class ModuleHandler {
public:
    std::vector<Module*> modules;

public:

    struct CompareArg { bool operator()(Module* mod1, Module* mod2) { return mod1->name < mod2->name; } };

    void InitModules() {
        _logf(L"[TreroInternal]: Registering modules...\n");

        std::string combat = "Combat";
        std::string world = "World";
        std::string player = "Player";
        std::string flies = "Flies";
        std::string visual = "Visual";
        std::string debug = "Debug";
        std::string misc = "Misc";

        //modules.push_back(new Criticals(combat));

        modules.push_back(new AirJump(world));
        modules.push_back(new Antibot(world));
        modules.push_back(new AntiVoid(world));
        modules.push_back(new NoPacket(world));
        modules.push_back(new Timer(world));
        modules.push_back(new Blink(world));
        modules.push_back(new Noclip(world));

        modules.push_back(new AirStuck(player));
        modules.push_back(new AutoWalk(player));
        modules.push_back(new FastWater(player));
        modules.push_back(new Glide(player));
        modules.push_back(new HighJump(player));
        modules.push_back(new Jesus(player));
        modules.push_back(new Bhop(player));
        modules.push_back(new Spider(player));
        modules.push_back(new Step(player));
        modules.push_back(new ReverseStep(player));
        modules.push_back(new Phase(player));
        modules.push_back(new NoFall(player));

        modules.push_back(new OGMFlight(flies));
        modules.push_back(new CreativeFly(flies));
        modules.push_back(new NoYFlight(flies));
        modules.push_back(new Jetpack(flies));

        modules.push_back(new Watermark(visual));
        modules.push_back(new ExpandScreen(visual));
        modules.push_back(new ArrayList(visual));
        modules.push_back(new Freelook(visual));
        modules.push_back(new Freecam(visual));
        modules.push_back(new NoSwing(visual));
        modules.push_back(new Zoom(visual));

        modules.push_back(new TestModule(debug));
        modules.push_back(new DebugCursor(debug));

        modules.push_back(new Killgame(misc));

        // Sort modules
        std::sort(modules.begin(), modules.end(), CompareArg());

        _logf(L"[TreroInternal]: Registered modules!\n");
    }

    void FrameRender(RenderUtils* ctx) {
        for (auto mod : modules)
            if (mod->enabled) {
                mod->OnFrameRender(ctx);
            }
    }
};

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
#include "Modules/Freecam.h"
#include "Modules/ReverseStep.h"
#include "Modules/ArrayList.h"
#include "Modules/Blink.h"
#include "Modules/Spider.h"
#include "Modules/Jesus.h"
#include "Modules/CreativeFly.h"
#include "Modules/DebugMenu.h"
#include "Modules/NoFall.h"
#include "Modules/AirSwim.h"
#include "Modules/SpinAttack.h"

class ModuleHandler {
public:
    std::vector<Module*> modules;

public:

    struct CompareArg { bool operator()(Module* mod1, Module* mod2) { return mod1->name < mod2->name; } };

    void InitModules() {
        _logf(L"[TreroInternal]: Registering modules...\n");

        std::string world = "World";
        std::string player = "Player";
        std::string misc = "Misc";
        std::string flies = "Flies";
        std::string visual = "Visual";
        std::string debug = "Debug";

        modules.push_back(new AirJump(world));
        modules.push_back(new Antibot(world));
        modules.push_back(new NoPacket(world)); // got it working but for some reason enable and disable are reversed? OH WAIT I KNOW WHY!
        // Scaffold -- cant do this until i learn GameMode in LP
        // Teleport -- Dont need this due to .tp
        modules.push_back(new Timer(world));
        // Tower -- Could do
        modules.push_back(new Blink(world));
        modules.push_back(new Noclip(world));

        // modules.push_back(new Module("Combat", "", 0x07));
        // RapidHit
        // Reach -- I wonder how you would go about reach internally lol? i think i know how actually i would sig scan then covert it to a float*

        modules.push_back(new AirStuck(player));
        modules.push_back(new AirSwim(player));
        //modules.push_back(new AutoWalk(player));//needs a fix for using Cos,...
        modules.push_back(new FastWater(player));
        modules.push_back(new Glide(player));
        modules.push_back(new HighJump(player));
        modules.push_back(new Jesus(player));
        // InventoryMove
        // Jesus
        // LongJump
        // RapidPlace
        // Speed
        modules.push_back(new Spider(player));
        modules.push_back(new Step(player));
        modules.push_back(new SpinAttack(player));
        modules.push_back(new ReverseStep(player));
        // Velocity
        // Bhop
        // Gamemode
        modules.push_back(new Phase(player));
        modules.push_back(new NoFall(player));

        
        // Disabler
        // InPvPTower
        // Masturbator
        // StreamMode
        // MineplexStep
        // AntiImmobile
        // NoLagback
        // Eject
        // FixHitBox
        // Freecam
        // Jump
        // KillGame
        // LoadConfig
        // SaveConfig
        // Welcome

        // BhopFlight
        // CreativeFlight
        // ElytraFlight
        // FastFlight
        // Flight
        // HiveFlight
        // Jetpack
        //modules.push_back(new OGMFlight(flies));//needs a fix for using Cos,...
        modules.push_back(new CreativeFly(flies));
        // TeleportPhase

        modules.push_back(new Watermark(visual));
        modules.push_back(new ExpandScreen(visual));
        modules.push_back(new ArrayList(visual));
        // ClickGUI
        // CoordsHud
        modules.push_back(new Freelook(visual));
        modules.push_back(new Freecam(visual));
        modules.push_back(new NoSwing(visual));
        // RainbowEffects
        modules.push_back(new Zoom(visual));

        modules.push_back(new TestModule(debug));
        modules.push_back(new DebugMenu(debug));
        modules.push_back(new DebugCursor(debug));
        // HiveBhop

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

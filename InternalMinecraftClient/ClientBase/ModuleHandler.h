#pragma once

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

class ModuleHandler {
public:
    std::vector<Module*> modules;

public:
    void InitModules() {
        _logf(L"[TreroInternal]: Registering modules...\n");

        modules.push_back(new AirJump("World"));
        modules.push_back(new Antibot("World"));
        modules.push_back(new NoPacket("World")); // got it working but for some reason enable and disable are reversed? OH WAIT I KNOW WHY!
        // Scaffold -- cant do this until i learn GameMode in LP
        // Teleport -- Dont need this due to .tp
        modules.push_back(new Timer("World"));
        // Tower -- Could do
        // Blink -- NoPacket
        modules.push_back(new Noclip("World"));

        // modules.push_back(new Module("Combat", "", 0x07));
        // RapidHit
        // Reach -- I wonder how you would go about reach internally lol? i think i know how actually i would sig scan then covert it to a float*

        modules.push_back(new AirStuck("Player"));
        modules.push_back(new AutoWalk("Player"));
        modules.push_back(new FastWater("Player"));
        modules.push_back(new Glide("Player"));
        modules.push_back(new HighJump("Player"));
        // InventoryMove
        // Jesus
        // LongJump
        // RapidPlace
        // Speed
        // Spider
        // Step
        // Velocity
        // Bhop
        // Gamemode
        modules.push_back(new Phase("Player"));

        modules.push_back(new DebugCursor("Misc"));
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
        modules.push_back(new OGMFlight("Flies"));
        // TeleportPhase

        modules.push_back(new Watermark("Visual"));
        modules.push_back(new ExpandScreen("Visual"));
        // ArrayList
        // ClickGUI
        // CoordsHud
        modules.push_back(new Freelook("Visual"));
        // Freecam
        modules.push_back(new NoSwing("Visual"));
        // RainbowEffects
        modules.push_back(new Zoom("Visual"));

        modules.push_back(new TestModule("Debug"));
        // HiveBhop

        _logf(L"[TreroInternal]: Registered modules!\n");
    }

    void FrameRender(RenderUtils* ctx) {
        for (auto mod : modules)
            if (mod->enabled) {
                mod->OnFrameRender(ctx);
            }
    }
};
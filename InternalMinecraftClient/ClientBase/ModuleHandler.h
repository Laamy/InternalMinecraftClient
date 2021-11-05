#pragma once

#define PI 3.14159265359 // 3.14159265359

#include "Modules/AirJump.h"
#include "Modules/TestModule.h"
#include "Modules/DebugCursor.h"
#include "Modules/Watermark.h"
#include "Modules/AirStuck.h"
#include "Modules/AutoWalk.h"
#include "Modules/OGMFlight.h"

class ModuleHandler {
public:
    std::vector<Module*> modules;

public:
    void InitModules() {
        _logf(L"[TreroInternal]: Registering modules...\n");

        modules.push_back(new AirJump("World"));
        // Antibot
        // NoPacket
        // Scaffold
        // Teleport
        // Timer
        // Tower
        // Blink
        // Noclip
        // Freecam

        modules.push_back(new Module("Combat", "", 0x07));
        // RapidHit
        // Reach -- I wonder how you would go about reach internally lol? i think i know how actually i would sig scan then covert it to a float*

        modules.push_back(new AirStuck("Player"));
        modules.push_back(new AutoWalk("Player"));
        // FastWater
        // Glide
        // HighJump
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
        // Phase

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
        modules.push_back(new OGMFlight("OGMFlight"));
        // TeleportPhase

        modules.push_back(new Watermark("Visual"));
        // ArrayList
        // ClickGUI
        // CoordsHud
        // Freelook
        // NoSwing
        // RainbowEffects
        // Zoom

        modules.push_back(new Module("Debug", "", 0x07));
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
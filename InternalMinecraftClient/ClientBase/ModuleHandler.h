#pragma once

#include <algorithm>

#define PI 3.14159265359 // 3.14159265359

#include "Modules/AirJump.h"
#include "Modules/TestModule.h"
#include "Modules/DebugCursor.h"
#include "Modules/Watermark.h"
#include "Modules/HiveFly.h"
#include "Modules/AirStuck.h"
#include "Modules/AutoWalk.h"
#include "Modules/Reach.h"
#include "Modules/OGMFlight.h"
#include "Modules/Tornado.h"
#include "Modules/ExpandScreen.h"
#include "Modules/FastWater.h"
#include "Modules/Godmode.h"
#include "Modules/Glide.h"
#include "Modules/ChestRay.h"
#include "Modules/CreativeMode.h"
#include "Modules/AntiImmobile.h"
#include "Modules/Spammer.h"
#include "Modules/Crasher.h"
#include "Modules/HighJump.h"
#include "Modules/Zoom.h"
#include "Modules/NoSwing.h"
#include "Modules/SpinAttack.h"
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
#include "Modules/Airswim.h"
#include "Modules/AutoSprint.h"
#include "Modules/Jesus.h"
#include "Modules/StreamName.h"
#include "Modules/CreativeFly.h"
#include "Modules/DebugMenu.h"
#include "Modules/NoFall.h"
#include "Modules/LifeboatFly.h"
#include "Modules/NoYFlight.h"
#include "Modules/Bhop.h"
#include "Modules/Jetpack.h"
#include "Modules/Criticals.h"
#include "Modules/AntiVoid.h"
#include "Modules/NoBrakes.h"
#include "Modules/AntiLagBack.h"
#include "Modules/Hitbox.h"
#include "Modules/Killaura.h"
#include "Modules/Uninject.h"
#include "Modules/AlwaysDay.h"
#include "Modules/Velocity.h"
#include "Modules/Notifications.h"
#include "Modules/NoShadow.h"
#include "Modules/NoAnimations.h"
#include "Modules/LDFreelook.h"
#include "Modules/AutoSneak.h"
#include "Modules/InventoryMove.h"

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
        std::string flies = "Flys";
        std::string visual = "Visual";
        std::string debug = "Debug";
        std::string misc = "Misc";

        modules.push_back(new Criticals(combat));
        modules.push_back(new Hitbox(combat));
        modules.push_back(new Killaura(combat));
        //modules.push_back(new Reach(combat)); // for now because not werking :/
        modules.push_back(new SpinAttack(combat));
        modules.push_back(new Tornado(combat));

        modules.push_back(new AirJump(world));
        modules.push_back(new Antibot(world));
        modules.push_back(new AntiVoid(world));
        modules.push_back(new NoPacket(world));
        modules.push_back(new Timer(world));
        modules.push_back(new Blink(world));
        modules.push_back(new Noclip(world));
        modules.push_back(new ChestRay(world));
        modules.push_back(new AlwaysDay(world));

        modules.push_back(new AirStuck(player));
        modules.push_back(new AutoSprint(player));
        modules.push_back(new Airswim(player));
        modules.push_back(new AutoWalk(player));
        modules.push_back(new FastWater(player));
        modules.push_back(new Glide(player));
        modules.push_back(new HighJump(player));
        modules.push_back(new Jesus(player));
        modules.push_back(new Bhop(player));
        modules.push_back(new AntiImmobile(player));
        modules.push_back(new AutoSneak(player));
        modules.push_back(new Spider(player));
        modules.push_back(new Step(player));
        modules.push_back(new ReverseStep(player));
        modules.push_back(new Phase(player));
        modules.push_back(new NoFall(player));
        modules.push_back(new NoBrakes(player));
        modules.push_back(new Velocity(player));
        modules.push_back(new AntiLagBack(player));
        modules.push_back(new InventoryMove(player));

        modules.push_back(new OGMFlight(flies));
        modules.push_back(new CreativeFly(flies));
        modules.push_back(new NoYFlight(flies));
        modules.push_back(new Jetpack(flies));
        modules.push_back(new HiveFly(flies));

        modules.push_back(new Watermark(visual));
        modules.push_back(new ExpandScreen(visual));
        modules.push_back(new ArrayList(visual));
        modules.push_back(new Freelook(visual));
        modules.push_back(new Freecam(visual));
        modules.push_back(new NoSwing(visual));
        modules.push_back(new StreamName(visual));
        modules.push_back(new Zoom(visual));
        modules.push_back(new Notifications(visual));
        modules.push_back(new NoShadow(visual));
        modules.push_back(new NoAnimations(visual));
        modules.push_back(new LDFreelook(visual));

        modules.push_back(new TestModule(debug)); //make sure to // these out before releasein
        modules.push_back(new DebugCursor(debug));

        modules.push_back(new Killgame(misc));
        modules.push_back(new CreativeMode(misc)); //once we have module setting it could be a module where u can change the gamemode or we could make it a command
        modules.push_back(new Crasher(misc));
        modules.push_back(new Godmode(misc));
        modules.push_back(new Spammer(misc));
        modules.push_back(new Uninject(misc));

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
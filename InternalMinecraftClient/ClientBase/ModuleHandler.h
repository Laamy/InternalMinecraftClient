#pragma once

#include <algorithm>

#define PI 3.14159265359 // 3.14159265359

#include "Modules/AirJump.h"
#include "Modules/TestModule.h"
#include "Modules/DebugCursor.h"
#include "Modules/Watermark.h"
#include "Modules/HiveFly.h"
#include "Modules/InvCleaner.h"
#include "Modules/AirStuck.h"
#include "Modules/AutoWalk.h"
#include "Modules/PlayerList.h"
#include "Modules/Reach.h"
#include "Modules/OGMFlight.h"
#include "Modules/ChestDumper.h"
#include "Modules/Tornado.h"
#include "Modules/ExpandScreen.h"
#include "Modules/NoObstructionSwing.h"
#include "Modules/FluxSwing.h"
#include "Modules/ShulkerNest.h"
#include "Modules/FloppySwing.h"
#include "Modules/FastWater.h"
#include "Modules/8BitSwing.h"
#include "Modules/Godmode.h"
#include "Modules/Glide.h"
#include "Modules/ChestRay.h"
#include "Modules/ChestStealer.h"
#include "Modules/NoSlow.h"
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
#include "Modules/Timer.h"
#include "Modules/Noclip.h"
#include "Modules/Phase.h"
#include "Modules/Step.h"
#include "Modules/Killgame.h"
#include "Modules/ReverseStep.h"
#include "Modules/ArrayList.h"
#include "Modules/Spider.h"
#include "Modules/Airswim.h"
#include "Modules/AutoSprint.h"
#include "Modules/Jesus.h"
#include "Modules/StreamName.h"
#include "Modules/CreativeFly.h"
#include "Modules/DebugMenu.h"
#include "Modules/NoWeb.h"
#include "Modules/NoFall.h"
#include "Modules/NoYFlight.h"
#include "Modules/Bhop.h"
#include "Modules/Jetpack.h"
#include "Modules/Criticals.h"
#include "Modules/AntiVoid.h"
#include "Modules/NoBrakes.h"
#include "Modules/AntiLagBack.h"
#include "Modules/Hitbox.h"
#include "Modules/Killaura.h"
#include "Modules/NoWater.h"
#include "Modules/Uninject.h"
#include "Modules/AlwaysDay.h"
#include "Modules/Velocity.h"
#include "Modules/Notifications.h"
#include "Modules/NoShadow.h"
#include "Modules/NoAnimations.h"
#include "Modules/LDFreelook.h"
#include "Modules/AutoSneak.h"
#include "Modules/InventoryMove.h"
#include "Modules/OldSwing.h"
#include "Modules/PushSwing.h"
#include "Modules/AntiFreeze.h"
#include "Modules/ElytraSpoof.h"
#include "Modules/ViewModel.h"
#include "Modules/Instabreak.h"
#include "Modules/CoordsHud.h"
#include "Modules/BlockReach.h"

// IN DEVELOPMENT!
#include "Modules/NameTags.h"
#include "Modules/Tracers.h"

class ModuleHandler {
public:
    std::vector<Module*> modules;

public:

    struct CompareArg { bool operator()(Module* mod1, Module* mod2) { return mod1->name < mod2->name; } };

    void InitModules() {
        _logf(L"[TreroInternal]: Registering modules...\n");

        // How to know what module goes where !
        std::string local = "LocalWorld"; // Local world only
        std::string combat = "Combat"; // PvP helpful
        std::string world = "World"; // World interacts with player (When you step in water step down a block jump ect)
        std::string flies = "Flies"; // Ability to go farther then the normal player can in distance
        std::string visual = "Visual"; // Visual effects
        std::string player = "Player"; // Player interacts with the world
        std::string misc = "Misc"; // other
        std::string swing = "Swing"; // other

        modules.push_back(new Criticals(combat));
        modules.push_back(new Hitbox(combat));
        modules.push_back(new Killaura(combat));
        modules.push_back(new Reach(combat));
        modules.push_back(new SpinAttack(combat));
        //modules.push_back(new Tornado(combat)); //no point

        modules.push_back(new AirJump(world));
        modules.push_back(new Antibot(world));
        modules.push_back(new AntiVoid(world));
        modules.push_back(new Timer(world));
        modules.push_back(new Noclip(world));
        modules.push_back(new NoWater(world));
        modules.push_back(new ReverseStep(world));
        modules.push_back(new AirStuck(world));
        modules.push_back(new Jesus(world));
        modules.push_back(new StreamName(world));
        modules.push_back(new HighJump(world));
        modules.push_back(new Instabreak(world));
        modules.push_back(new Spider(world));
        modules.push_back(new Step(world));

        modules.push_back(new AutoSprint(player));
        modules.push_back(new Airswim(player));
        modules.push_back(new AutoWalk(player));
        modules.push_back(new InvCleaner(player));
        modules.push_back(new FastWater(player));
        modules.push_back(new Glide(player));
        modules.push_back(new Bhop(player));
        modules.push_back(new AutoSneak(player));
        modules.push_back(new Phase(player));
        modules.push_back(new ChestStealer(player));
        modules.push_back(new ChestDumper(player));
        modules.push_back(new NoFall(player));
       // modules.push_back(new NoBrakes(player));
        modules.push_back(new Velocity(player));
        modules.push_back(new InventoryMove(player));
        modules.push_back(new NoWeb(player));

        modules.push_back(new OGMFlight(flies));
        modules.push_back(new CreativeFly(flies));
        modules.push_back(new NoYFlight(flies));
        modules.push_back(new Jetpack(flies));
        modules.push_back(new HiveFly(flies));
        modules.push_back(new ElytraSpoof(flies));

        modules.push_back(new PlayerList(visual));
        modules.push_back(new ArrayList(visual));
        modules.push_back(new Freelook(visual));
        modules.push_back(new Zoom(visual));
        modules.push_back(new Notifications(visual));
        modules.push_back(new Watermark(visual));
        modules.push_back(new NoShadow(visual));
        modules.push_back(new NoAnimations(visual));
        modules.push_back(new LDFreelook(visual));
        modules.push_back(new ChestRay(visual));
        modules.push_back(new AlwaysDay(visual));
        modules.push_back(new Tracers(visual));
        modules.push_back(new CoordsHud(visual));

        modules.push_back(new Killgame(misc));
        modules.push_back(new CreativeMode(misc)); 
        modules.push_back(new Crasher(misc));
        modules.push_back(new Godmode(misc));
        modules.push_back(new Spammer(misc));
        modules.push_back(new Uninject(misc));
        modules.push_back(new ExpandScreen(misc));
        modules.push_back(new NoSlow(misc));
        modules.push_back(new AntiImmobile(misc));
        modules.push_back(new AntiLagBack(misc));
        modules.push_back(new AntiFreeze(misc));
        modules.push_back(new ShulkerNest(misc));
        modules.push_back(new TestModule(misc));
        modules.push_back(new DebugCursor(misc));
        modules.push_back(new BlockReach(misc));

        modules.push_back(new NoObstructionSwing(swing));
        modules.push_back(new FluxSwing(swing));
        modules.push_back(new EightBitSwing(swing));
        modules.push_back(new OldSwing(swing));
        modules.push_back(new PushSwing(swing));
        modules.push_back(new FloppySwing(swing));
        modules.push_back(new NoSwing(swing));
        modules.push_back(new ViewModel(swing));
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
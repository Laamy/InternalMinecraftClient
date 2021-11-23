#pragma once

class HighJump : public Module {
public:
    HighJump(std::string cat) : Module(cat, "HighJump", "Jump higher then normal", 0x07) {};

    void OnGameTick(Actor* lp) override {
        if (lp->onGround2 && keymap[(int)' '])
            lp->Velocity.y = 1.0f;
    }
};
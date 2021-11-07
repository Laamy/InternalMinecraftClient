#pragma once

class HighJump : public Module {
public:
    HighJump(std::string cat) : Module(cat, "HighJump", 0x07) {};

    void OnGameTick(Actor* lp) override {
        if (keymap[(int)' '] && lp->onGround || keymap[(int)' '] && lp->onGround2 || keymap[(int)' '] && lp->onGround3) {
            lp->Velocity.y = 1.0f;
        }
    };
};

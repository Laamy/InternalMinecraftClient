#pragma once

class Jesus : public Module {
public:
    Jesus(std::string cat) : Module(cat, "Jesus", 0x07) {};

    void OnGameTick(Actor* lp) override {
        if (lp->IsInWater || lp->IsInLava) {
            lp->Velocity.y = 0.2f;
            lp->onGround = true;
        }
    }
};
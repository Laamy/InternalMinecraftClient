#pragma once

class Jesus : public Module {
public:
    Jesus(std::string cat) : Module(cat, "Jesus", "Walk on water like jesus", 0x07) {};

    void OnGameTick(Actor* lp) override {
        if (lp->IsInWater || lp->IsInLava) {
            lp->Velocity.y = 0.025f;
            lp->onGround = true;
        }
    }
};

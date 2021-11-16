#pragma once

class Glide : public Module {
public:
    Glide(std::string cat) : Module(cat, "Glide", 0x07) {};

    void OnGameTick(Actor* lp) override {
        lp->Velocity.y = -0.01f;
    }
};
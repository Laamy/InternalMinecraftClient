#pragma once

class FastWater : public Module {
public:
    FastWater(std::string cat) : Module(cat, "FastWater", 0x07) {};
    float speed = 0.44;

    void OnGameTick(Actor* lp) override {
        if (lp->IsInWater || lp->IsInLava)
        {
            auto cy = (lp->CameraRots.y + 90) * 0.01745329251f;

            lp->Velocity.x = sin(cy) * 2;
            lp->Velocity.y = 0.01f;
            lp->Velocity.z = cos(cy) * 2;
        }
    };
};
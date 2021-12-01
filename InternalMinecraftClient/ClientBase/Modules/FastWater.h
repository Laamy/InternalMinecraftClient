#pragma once

class FastWater : public Module {
public:
    FastWater(std::string cat) : Module(cat, "FastWater", "Become a speed boat!", 0x07) {};

    void OnGameTick(Actor* lp) override {
        if (lp->IsInWater || lp->isInLava())
        {
            float yaw = (float)lp->bodyRots()->y;

            lp->Velocity.z = sin((yaw + 90) * 0.01745329251f) * 0.44f;
            lp->Velocity.x = cos((yaw + 90) * 0.01745329251f) * 0.44f;
            
        }
    }
};

#pragma once

class NoWater : public Module {
public:
    NoWater(std::string cat) : Module(cat, "NoWater", "Acts as if there is no water", 0x07) {};

    void OnGameTick(Actor* lp) override {
        if (lp->IsInWater || lp->IsInLava) {
            lp->IsInWater = 0;
            lp->IsInLava = 0;
            lp->stopSwimming();
            lp->isInWater(false);
            lp->hasEnteredWater(false);
        }
        
    }
};

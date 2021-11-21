#pragma once

class CreativeFly : public Module {
public:
    CreativeFly(std::string cat) : Module(cat, "CreativeFly", 'R') {};
    
    void OnEnable(ClientInstance* ci, Actor* lp) override {
        lp->IsFlying = true;
        lp->CanFly = true;
    }

    void OnDisable(ClientInstance* ci, Actor* lp) override {
        lp->IsFlying = false;
        lp->CanFly = false;
    }
};

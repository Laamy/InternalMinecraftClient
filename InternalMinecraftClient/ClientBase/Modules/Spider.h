#pragma once

class Spider : public Module {
public:
	Spider(std::string cat) : Module(cat, "Spider", "Climb up walls like a spider", 0x07) {};

	void OnGameTick(Actor* lp) override {
		if (lp->walkingIntoObj)
			lp->Velocity.y = 0.35f;
	}
};
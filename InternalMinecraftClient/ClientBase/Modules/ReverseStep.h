#pragma once

class ReverseStep : public Module {
public:
	ReverseStep(std::string cat) : Module(cat, "ReverseStep", "Decrease your step height", 0x07) {};

	void OnGameTick(Actor* lp) override {
		if (lp->onGround && lp->Velocity.y < 0 && !(lp->Velocity.y < -1)) // requirements for reverse step
			lp->Velocity.y = -5;
	}
};
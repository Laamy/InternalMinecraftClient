#pragma once

class ReverseStep : public Module {
public:
	ReverseStep(std::string cat) : Module(cat, "ReverseStep", (int)'R') {};

	void OnGameTick(Actor* lp) override {
		if (lp == nullptr) return;

		if (lp->onGround && lp->Velocity.y < 0 && !(lp->Velocity.y < -1)) // requirements for reverse step
			lp->Velocity.y = -5;
	};
};
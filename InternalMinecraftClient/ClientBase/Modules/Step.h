#pragma once

class Step : public Module {
public:
	Step(std::string cat) : Module(cat, "Step", "Increase your step height", 0x07) {};

	void OnGameTick(Actor* lp) override {
		lp->stepHeight = 2;
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		lp->stepHeight = 0.5625f;
	}
};
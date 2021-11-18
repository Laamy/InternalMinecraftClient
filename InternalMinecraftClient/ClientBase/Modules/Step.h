#pragma once

class Step : public Module {
public:
	Step(std::string cat) : Module(cat, "Step", 0x07) {};

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		if (lp == nullptr) return;

		lp->stepHeight = 2;
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		if (lp == nullptr) return;

		lp->stepHeight = 0.5f;
	}
};
#pragma once

class Step : public Module {
public:
	Step(std::string cat) : Module(cat, "Step", 0x07) {};

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		if (lp == nullptr) return;

		lp->StepHeight = 3;
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		if (lp == nullptr) return;

		lp->StepHeight = 0.5f;
	}
};
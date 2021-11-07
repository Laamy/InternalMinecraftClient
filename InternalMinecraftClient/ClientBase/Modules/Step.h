#pragma once

class Step : public Module {
public:
	Step(std::string cat) : Module(cat, "Step", (int)'R') {};

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		if (lp == nullptr) return;

		lp->StepHeight = 2;
	};

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		if (lp == nullptr) return;

		lp->StepHeight = 0.5f;
	};
};
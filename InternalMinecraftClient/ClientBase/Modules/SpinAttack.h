#pragma once

class SpinAttack : public Module {
public:
	SpinAttack(std::string cat) : Module(cat, "SpinAttack", 0x07) {};

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		lp->startSpinAttack();
	}

	void OnGameTick(Actor* lp) override {
		lp->startSpinAttack();
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		lp->stopSpinAttack();
	}
};
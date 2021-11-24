#pragma once

class SpinAttack : public Module {
public:
	SpinAttack(std::string cat) : Module(cat, "SpinAttack","Spin like crazy, and deal damage!", 0x07) {};

	void OnGameTick(Actor* lp) override {
		lp->startSpinAttack();
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		lp->stopSpinAttack();
	}
};
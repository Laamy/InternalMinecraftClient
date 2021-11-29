#pragma once

class SpinAttack : public Module {
public:
	SpinAttack(std::string cat) : Module(cat, "SpinAttack", "You spin my world right round, bae right round.", 0x07) {};

	void OnGameTick(Actor* lp) override {
		auto localPlayer = clientInst->getCPlayer();
		localPlayer->startSpinAttack();
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		auto localPlayer = clientInst->getCPlayer();
		localPlayer->stopSpinAttack();
	}
};
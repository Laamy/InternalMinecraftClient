#pragma once

class SpinAttack : public Module {
public:
	SpinAttack(std::string cat) : Module(cat, "SpinAttack", 0x07) {};
	vLocalPlayer* player;
	void OnEnable(ClientInstance* ci, Actor* lp) override {
		player->startSpinAttack();
	};

	void OnGameTick(Actor* lp) override {
		player->startSpinAttack();
	};

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		player->stopSpinAttack();
	};
};
#pragma once

class Velocity : public Module {
public:
	Velocity(std::string cat) : Module(cat, "Velocity", 0x0) {};
	void OnGameTick(Actor* lp) override {
		auto player = clientInst->getCPlayer();
		if (player->HurtTime >= 1)//dosent work :/
			player->Velocity = {0, 0, 0};
	}
};
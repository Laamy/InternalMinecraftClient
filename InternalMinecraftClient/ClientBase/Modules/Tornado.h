#pragma once

class Tornado : public Module {
public:
	Tornado(std::string cat) : Module(cat, "Tornado", "Spin and damage nearby mobs", 0x07) {};

	void OnGameTick(Actor* lp) override {
		lp->setDamageNearbyMobs(true);
	}
};
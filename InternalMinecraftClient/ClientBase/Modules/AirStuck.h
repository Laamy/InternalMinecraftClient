#pragma once

class AirStuck : public Module {
public:
	AirStuck(std::string cat) : Module(cat, "AirStuck", 0x07) {};

	void OnGameTick(Actor* lp) override {
		lp->Velocity = {0, 0, 0};
	}
};
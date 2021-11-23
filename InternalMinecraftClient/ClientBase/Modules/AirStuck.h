#pragma once

class AirStuck : public Module {
public:
	AirStuck(std::string cat) : Module(cat, "AirStuck", "Get stuck as hard as your step sister when she was trying to do the washing ;)", 0x07) {};

	void OnGameTick(Actor* lp) override {
		lp->Velocity = {0, 0, 0};
	}
};
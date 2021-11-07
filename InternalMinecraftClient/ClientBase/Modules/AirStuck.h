#pragma once

class AirStuck : public Module {
public:
	AirStuck(std::string cat) : Module(cat, "AirStuck", 0x07) {};

	void OnGameTick(Actor* lp) override {
		lp->Velocity = Vector3(0, 0, 0);
	};
};
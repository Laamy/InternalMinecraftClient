#pragma once

class OGMFlight : public Module {
public:
	OGMFlight(std::string cat) : Module(cat, "OGMFlight", 0x07) {};
    float speedMod = 0.7f;

	void OnGameTick(Actor* lp) override {
		lp->Velocity.x = cos((lp->bodyRots()->y + 90) * 0.01745329251f) * speedMod;
		lp->Velocity.y = 0.075f * speedMod;
		lp->Velocity.z = sin((lp->bodyRots()->y + 90) * 0.01745329251f) * speedMod;
	};
};

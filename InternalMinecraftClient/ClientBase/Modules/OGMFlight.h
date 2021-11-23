#pragma once

class OGMFlight : public Module {
public:
	OGMFlight(std::string cat) : Module(cat, "OGMFlight", "OG MineplexFly", 0x07) {};

	void OnGameTick(Actor* lp) override {
		lp->Velocity.x = cos((lp->bodyRots()->y + 90) * 0.01745329251f) * 0.7f;
		lp->Velocity.y = 0.075f * 0.7f;
		lp->Velocity.z = sin((lp->bodyRots()->y + 90) * 0.01745329251f) * 0.7f;
	}
};
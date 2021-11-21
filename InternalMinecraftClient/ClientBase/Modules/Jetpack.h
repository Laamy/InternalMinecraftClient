#pragma once

class Jetpack : public Module {
public:
	Jetpack(std::string cat) : Module(cat, "Jetpack", 'F') {};
	bool HoldMode() {
		return true;
	}

	void OnGameTick(Actor* lp) override {
			auto calcYaw = (lp->bodyRots()->y + 90) * ((float)PI / 180);
			auto calcPitch = (lp->bodyRots()->x) * -((float)PI / 180);

			lp->Velocity.x = (float)cos(calcYaw) * 1.5f;
			lp->Velocity.y = (float)sin(calcPitch) * 1.5f;
			lp->Velocity.z = (float)sin(calcYaw) * 1.5f;
	}
};

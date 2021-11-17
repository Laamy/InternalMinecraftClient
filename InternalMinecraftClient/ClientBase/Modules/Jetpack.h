#pragma once

class Jetpack : public Module {
public:
	Jetpack(std::string cat) : Module(cat, "Jetpack", 0x07) {};
	float speedMod = 1.5f;

	void OnGameTick(Actor* lp) override {
		if (keymap['F']) {
			auto calcYaw = (lp->bodyRots()->y + 90) * ((float)PI / 180);
			auto calcPitch = (lp->bodyRots()->x) * -((float)PI / 180);

			lp->Velocity.x = (float)cos(calcYaw) * speedMod;
			lp->Velocity.y = (float)sin(calcPitch) * speedMod;
			lp->Velocity.z = (float)sin(calcYaw) * speedMod;
		}
	};
};

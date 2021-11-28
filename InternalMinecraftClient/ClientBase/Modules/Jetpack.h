#pragma once

class Jetpack : public Module {
public:
	Jetpack(std::string cat) : Module(cat, "Jetpack", "Get a magical jetpack!", 'F') {};
	bool HoldMode() {
		return true;
	}

	void OnGameTick(Actor* lp) override {
			auto calcYaw = (lp->bodyRots()->y + 90) * ((float)PI / 180);
			auto calcPitch = (lp->bodyRots()->x) * -((float)PI / 180);

			lp->lerpybutworky(Vector3((float)cos(calcYaw) * 1.5f, (float)sin(calcPitch) * 1.5f, (float)sin(calcYaw) * 1.5f));
	}
};

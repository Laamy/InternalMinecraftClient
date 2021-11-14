#pragma once

class Jetpack : public Module {
public:
	Jetpack(std::string cat) : Module(cat, "Jetpack", 0x07) {};
	ClientInstance* ci;

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		if (lp == nullptr) return;
		this->ci = ci;
	};


	void OnGameTick(Actor* lp) override {
		if (lp == nullptr || ci == nullptr) return;

		if (keymap['W']) {
			auto calcYaw = (lp->bodyRots()->y + 90) * ((float)PI / 180);
			auto calcPitch = (lp->bodyRots()->x) * -((float)PI / 180);
			Vector3 newVel;

			newVel.x = (float)cos(calcYaw) * 2;
			newVel.y = (float)sin(calcPitch) * 2;
			newVel.z = (float)sin(calcYaw) * 2;

			lp->Velocity = newVel;
			lp->fallDistance = .0f;//works on world's and realm's
		}
		else {
			lp->Velocity = Vector3(0, 0, 0);
		}
	};

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		if (lp == nullptr) return;
		lp->Velocity = Vector3(0, 0, 0);
	};
};

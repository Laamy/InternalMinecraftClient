#pragma once

class NoYFlight : public Module {
public:
	NoYFlight(std::string cat) : Module(cat, "NoYFlight", 0x07) {};
	ClientInstance* ci;

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		if (lp == nullptr) return;
		this->ci = ci;
	};


	void OnGameTick(Actor* lp) override {
		if (lp == nullptr || ci == nullptr) return;

		if (keymap['W']) {
			auto calcYaw = (lp->bodyRots()->y + 90) * ((float)PI / 180);

			Vector3 newVel;

			newVel.x = (float)cos(calcYaw) * 2;
			newVel.y = 0;
			newVel.z = (float)sin(calcYaw) * 2;

			lp->Velocity = newVel;
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

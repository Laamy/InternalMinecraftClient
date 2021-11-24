#pragma once

class NoYFlight : public Module {
public:
	NoYFlight(std::string cat) : Module(cat, "NoYFlight", "Bypassing fly made for mineplex", 'R') {};
	ClientInstance* ci;

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		ci = ci;
	}

	void OnGameTick(Actor* lp) override {
		if (keymap['W']) {
			auto calcYaw = (lp->bodyRots()->y + 90) * ((float)PI / 180);

			Vector3 newVel;

			newVel.x = (float)cos(calcYaw) * 2;
			newVel.y = 0;
			newVel.z = (float)sin(calcYaw) * 2;

			lp->Velocity = newVel;
		}
		else
			lp->Velocity = {0, 0, 0};
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		lp->Velocity = {0, 0, 0};
	}
};
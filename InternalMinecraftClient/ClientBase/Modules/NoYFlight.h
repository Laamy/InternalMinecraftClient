#pragma once

class NoYFlight : public Module {
public:
	NoYFlight(std::string cat) : Module(cat, "NoYFlight", "Bypassing fly made for mineplex", 0x0) {};
	ClientInstance* ci;

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		this->ci = ci;
	}

	void OnGameTick(Actor* lp) override {
		float yaw = (float)lp->bodyRots()->y;
		lp->Velocity.x = 0.f;
		lp->Velocity.y = 0.f;
		lp->Velocity.z = 0.f;
		if (keymap['W']) {
			lp->Velocity.z = sin((yaw + 90) * 0.01745329251f) * 2;
			lp->Velocity.x = cos((yaw + 90) * 0.01745329251f) * 2;
		}
		if (keymap['A']) {
			lp->Velocity.z = sin((yaw + 0) * 0.01745329251f) * 2;
			lp->Velocity.x = cos((yaw + 0) * 0.01745329251f) * 2;
		}
		if (keymap['S']) {
			lp->Velocity.z = sin((yaw - 90) * 0.01745329251f) * 2;
			lp->Velocity.x = cos((yaw - 90) * 0.01745329251f) * 2;
		}
		if (keymap['D']) {
			lp->Velocity.z = sin((yaw + 180) * 0.01745329251f) * 2;
			lp->Velocity.x = cos((yaw + 180) * 0.01745329251f) * 2;
		}
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		lp->Velocity.x = 0.f;
		lp->Velocity.y = 0.f;
		lp->Velocity.z = 0.f;
	}
};
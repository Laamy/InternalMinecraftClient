#pragma once

class AutoWalk : public Module {
public:
	AutoWalk(std::string cat) : Module(cat, "AutoWalk", "Automatically walk forwards!", 0x07) {};

	void OnGameTick(Actor* lp) override {
		float yaw = (float)lp->bodyRots()->y;

		lp->Velocity.z = sin((yaw + 90) * 0.01745329251f) * 0.29f;
		lp->Velocity.x = cos((yaw + 90) * 0.01745329251f) * 0.29f;
	}
};
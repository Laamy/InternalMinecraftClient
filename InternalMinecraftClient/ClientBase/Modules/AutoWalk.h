#pragma once

class AutoWalk : public Module {
public:
	AutoWalk(std::string cat) : Module(cat, "AutoWalk", 0x07) {};
	float speed = 0.44;

	void OnGameTick(Actor* lp) override {
		float yaw = (float)lp->bodyRots()->y;

		lp->Velocity.z = sin((yaw + 90) * 0.01745329251f) * speed;
		lp->Velocity.x = cos((yaw + 90) * 0.01745329251f) * speed;
	};
};
#pragma once

class Bhop : public Module {
public:
	Bhop(std::string cat) : Module(cat, "Bhop", 0x07) {};
	float speed = 0.64;

	void OnGameTick(Actor* lp) override {
		float yaw = (float)lp->bodyRots()->y;

		lp->Velocity.z = sin((yaw + 90) * 0.01745329251f) * speed;
		lp->Velocity.x = cos((yaw + 90) * 0.01745329251f) * speed;
		if (lp->onGround) {
			lp->Velocity.y = 0.4;
		}
	};
};

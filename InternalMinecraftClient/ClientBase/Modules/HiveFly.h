#pragma once

class HiveFly : public Module {
public:
	HiveFly(std::string cat) : Module(cat, "HiveFly", "Turn it on, throw a pearl, then boom!", (int)'G') {};

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		ci->timerClass->setTimerSpeed(38); // wtf timer wont work
	}

	void OnGameTick(Actor* lp) override {
		float yaw = (float)lp->bodyRots()->y;
		float speed = 0.2f; // 0.180f
		lp->onGround = 1;
		lp->Velocity = 0, 0, 0;
			if (keymap['W']) {
				lp->Velocity.z = sin((yaw + 90) * 0.01745329251f) * speed; // 0.01745329251f
				lp->Velocity.x = cos((yaw + 90) * 0.01745329251f) * speed;
			}
			if (keymap['A']) {
				lp->Velocity.z = sin((yaw + 0) * 0.01745329251f) * speed;
				lp->Velocity.x = cos((yaw + 0) * 0.01745329251f) * speed;
			}
			if (keymap['S']) {
				lp->Velocity.z = sin((yaw - 90) * 0.01745329251f) * speed;
				lp->Velocity.x = cos((yaw - 90) * 0.01745329251f) * speed;
			}
			if (keymap['D']) {
				lp->Velocity.z = sin((yaw + 180) * 0.01745329251f) * speed;
				lp->Velocity.x = cos((yaw + 180) * 0.01745329251f) * speed;
			}
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		lp->Velocity = 0, 0, 0;
		ci->timerClass->setTimerSpeed(20);
	}
};
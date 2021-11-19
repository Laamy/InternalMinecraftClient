#pragma once

class LifeboatFly : public Module {
public:
	LifeboatFly(std::string cat) : Module(cat, "LifeboatFly", 0x07) {};
	ClientInstance* ci;
	bool blinking;
	int count;

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		ci = ci;
		blinking = false;
	}

	void OnGameTick(Actor* lp) override {
		float speed = 0.4f;

		ci->timerClass->timerClass->timer = 20.0f * speed;

		lp->onGround = true;

		float speed2 = 1.25f / speed;

		float cy = (lp->CameraRots.y + 90) * (PI / 180);

		if (keymap[(int)'W']) {
			lp->Velocity.x = sin(cy) * speed2;
			lp->Velocity.z = cos(cy) * speed2;
		}
		lp->Velocity.y = -0.001f;

		if (count > 7) {
			blinking = true;
			ci->loopbackSender->RetPacketSender();
			count = 0;
		}
		else {
			count++;
			blinking = false;
			ci->loopbackSender->RestorePacketSender();
		}
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		count = 0;
		if (!blinking) {
			ci->loopbackSender->RestorePacketSender();
			blinking = false;
		}
		ci->timerClass->timerClass->timer = 20.0f;
		lp->Velocity = {0, 0, 0};
	}
};
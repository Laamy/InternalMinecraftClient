#pragma once

class Bhop : public Module {
public:
	Bhop(std::string cat) : Module(cat, "Bhop", 'V') {};
	void OnGameTick(Actor* lp) override {
		float yaw = (float)lp->bodyRots()->y;
		if (keymap['W']) {
			lp->Velocity.z = sin((yaw + 90) * 0.01745329251f) * 0.44f;
			lp->Velocity.x = cos((yaw + 90) * 0.01745329251f) * 0.44f;
			if (lp->onGround) {
				lp->Velocity.y = 0.40f;
			}
		}
		if (keymap['A']) {
			lp->Velocity.z = sin((yaw + 0) * 0.01745329251f) * 0.44f;
			lp->Velocity.x = cos((yaw + 0) * 0.01745329251f) * 0.44f;
			if (lp->onGround) {
				lp->Velocity.y = 0.40f;
			}
		}
		if (keymap['S']) {
			lp->Velocity.z = sin((yaw - 90) * 0.01745329251f) * 0.44f;
			lp->Velocity.x = cos((yaw - 90) * 0.01745329251f) * 0.44f;
			if (lp->onGround) {
				lp->Velocity.y = 0.40f;
			}
		}
		if (keymap['D']) {
			lp->Velocity.z = sin((yaw + 180) * 0.01745329251f) * 0.44f;
			lp->Velocity.x = cos((yaw + 180) * 0.01745329251f) * 0.44f;
			if (lp->onGround) {
				lp->Velocity.y = 0.40f;
			}
		}
	}
};
#pragma once

class AutoWalk : public Module {
public:
	AutoWalk(std::string cat) : Module(cat, "AutoWalk", 0x07) {};
	float speed = 0.44;

	void OnTick(ClientInstance* ci) override {
		if (ci->localPlayer != nullptr) {
			auto lp = ci->localPlayer;

			float yaw = (float)lp->bodyRots()->y;

			lp->Velocity.z = sin(((float)yaw + 90) * 0.01745329251) * speed;
			lp->Velocity.x = cos(((float)yaw + 90) * 0.01745329251) * speed;
		}
	};
};
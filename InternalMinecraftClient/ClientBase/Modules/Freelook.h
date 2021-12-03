#pragma once

class Freelook : public Module {
public:
	Freelook(std::string cat) : Module(cat, "Freelook", "Freely look around client sidedly", 'C') {};
	bool HoldMode() {
		return true;
	}
	Vector2 oldPos;

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		oldPos = lp->CameraRots;
	}

	void OnGameTick(Actor* lp) override {
		if (oldPos != Vector2(0, 0)) {
			lp->CameraRots = oldPos;
			lp->BodyRotations.x = oldPos.y;
			lp->FirstPersonHandRotations.x = oldPos.y;
		}
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		oldPos = Vector2(0, 0);
	}
};
#pragma once

class Freelook : public Module {
public:
	bool HoldMode() {
		return true;
	}
	Freelook(std::string cat) : Module(cat, "Freelook", 'N') {};
	Vector2 oldPos;

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		oldPos = lp->CameraRots;
	}

	void OnGameTick(Actor* lp) override {
		if (oldPos != Vector2(0, 0))
			lp->CameraRots = oldPos;
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		oldPos = Vector2(0, 0);
	}
};
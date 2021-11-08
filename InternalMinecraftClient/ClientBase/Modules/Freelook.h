#pragma once

class Freelook : public Module {
public:
	Freelook(std::string cat) : Module(cat, "Freelook", 0x07) {};
	Vector2 oldPos;

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		if (lp == nullptr) return;

		oldPos = lp->CameraRots;
	};

	void OnGameTick(Actor* lp) override {
		if (lp == nullptr) return;

		if (oldPos != Vector2(0, 0))
			lp->CameraRots = oldPos;
	};

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		if (lp == nullptr) return;

		oldPos = Vector2(0, 0);
	};
};
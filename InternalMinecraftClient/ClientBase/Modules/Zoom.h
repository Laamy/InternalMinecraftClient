#pragma once

class Zoom : public Module { // worked
public:
	Zoom(std::string cat) : Module(cat, "Zoom", 0x07) {};
	float speed = 0.44;

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		lp->SetFieldOfView(0.2f);
	};

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		lp->SetFieldOfView(1);
	};
};	
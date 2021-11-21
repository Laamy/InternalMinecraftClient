#pragma once

class Zoom : public Module { // worked
public:
	Zoom(std::string cat) : Module(cat, "Zoom", 'C') {};

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		if (lp == nullptr) return;
			lp->SetFieldOfView(0.25f);
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		if (lp == nullptr) return;
		lp->SetFieldOfView(1);
	}
};

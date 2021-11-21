#pragma once

class Zoom : public Module { // worked
public:
	Zoom(std::string cat) : Module(cat, "Zoom", 'C') {};
	bool HoldMode() {
		return true;
	}
	void OnGameTick(Actor* lp) override {
		if (lp->CameraRots.x == 0) return;

		if (keymap['C'])
			lp->SetFieldOfView(0.25f);
		else
			lp->SetFieldOfView(1);
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		if (lp == nullptr) return;
		lp->SetFieldOfView(1);
	}
};

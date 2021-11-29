#pragma once

class Zoom : public Module {
public:
	Zoom(std::string cat) : Module(cat, "Zoom", "Decrease your fov then increase it again", 0x07) {};

	void OnEnable(ClientInstance* ci, Actor* lp) override {
			lp->SetFieldOfView(0.25f);
				cancelUiRender = true;
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		lp->SetFieldOfView(1.f);
		cancelUiRender = false;
	}

	void OnGameTick(Actor* lp) override {
		lp->SetFieldOfView(0.25f);
	}
};

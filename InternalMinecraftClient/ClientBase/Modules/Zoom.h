#pragma once

class Zoom : public Module {
public:
	Zoom(std::string cat) : Module(cat, "Zoom", 'X') {};//We need to make it so when we are typing in chat, it dosent activate modules hgdgdfhgdfh

	void OnEnable(ClientInstance* ci, Actor* lp) override {
			lp->SetFieldOfView(0.25f);
				cancelUiRender = true;
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		lp->SetFieldOfView(1);
		cancelUiRender = false;
	}

	void OnGameTick(Actor* lp) override {
		lp->SetFieldOfView(1);
		lp->SetFieldOfView(0.25f);
	}
};

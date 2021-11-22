#pragma once

class Zoom : public Module { // worked
public:
	Zoom(std::string cat) : Module(cat, "Zoom", 'X') {};//We need to make it so when we are typing in chat, it dosent activate modules hgdgdfhgdfh

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		if (lp == nullptr) return;
			lp->SetFieldOfView(0.25f);
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		if (lp == nullptr) return;
		lp->SetFieldOfView(1);
	}

	void OnGameTick(Actor* lp) override {
		lp->SetFieldOfView(1);
	}
};

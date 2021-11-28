#pragma once

class CreativeFly : public Module {
public:
	CreativeFly(std::string cat) : Module(cat, "CreativeFly", "Makes You Fly Like Creative Mode!", 0x07) {};
	bool isFlying;

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		isFlying = lp->IsFlying;
	}

	void OnGameTick(Actor* lp) override {
		lp->IsFlying = true;
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		lp->IsFlying = isFlying;
	}
};
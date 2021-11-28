#pragma once

class CreativeMode : public Module {
public:
	CreativeMode(std::string cat) : Module(cat, "CreativeMode", "Makes you in creative mode!", 0x07) {};
	int origGamemode;

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		origGamemode = lp->getGamemode();
	}

	void OnGameTick(Actor* lp) override {
		lp->setGamemode(1);
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		lp->setGamemode(origGamemode);
	}
};
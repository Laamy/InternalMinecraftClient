#pragma once

class CreativeMode : public Module {
public:
	CreativeMode(std::string cat) : Module(cat, "CreativeMode", "Makes you in creative mode!", VK_NUMPAD1) {};
	int origGamemode;

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		origGamemode = lp->getPlayerGameType();
	}

	void OnGameTick(Actor* lp) override {
		//lp->getGamemode() == 1;
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		//lp->getGamemode() = 1;
	}
};
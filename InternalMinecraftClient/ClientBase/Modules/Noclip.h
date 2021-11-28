#pragma once

class Noclip : public Module {
public:
	Noclip(std::string cat) : Module(cat, "Noclip", "Disable all collisions", 0x07) {};

	void OnGameTick(Actor* lp) override {
		lp->Position.upper.y = lp->Position.lower.y - 1.8f;
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		lp->setPos(lp->Position.lower);
	}
};
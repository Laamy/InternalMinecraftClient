#pragma once

class Hitbox : public Module {
public:
	Hitbox(std::string cat) : Module(cat, "Hitbox", 0x07) {};

	void OnGameTick(Actor* lp) override {
		lp->Hitbox.x = 7;
		lp->Hitbox.y = 7;
	}
};
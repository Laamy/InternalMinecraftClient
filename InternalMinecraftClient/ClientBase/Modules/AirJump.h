#pragma once

class AirJump : public Module {
public:
	AirJump(std::string cat) : Module(cat, "AirJump", "Jump on thinair!", 0x07) {};

	void OnGameTick(Actor* lp) override {
		lp->onGround = 1;
	}
};
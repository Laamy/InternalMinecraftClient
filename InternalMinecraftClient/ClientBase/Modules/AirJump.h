#pragma once

class AirJump : public Module {
public:
	AirJump(std::string cat) : Module(cat, "AirJump", 0x07) {};

	void OnTick(ClientInstance* ci) override {
		auto lp = ci->localPlayer;
		lp->onGround = 1;
	};
};
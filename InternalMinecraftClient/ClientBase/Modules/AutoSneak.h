#pragma once

class AutoSneak : public Module {
public:
	AutoSneak(std::string cat) : Module(cat, "AutoSneak", 0x07) {};
	vLocalPlayer* funcs;
	void OnGameTick(Actor* lp) override {
		funcs->setSneaking(true);
	};
};
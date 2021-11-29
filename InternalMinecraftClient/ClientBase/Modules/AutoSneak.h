#pragma once

class AutoSneak : public Module {
public:
	AutoSneak(std::string cat) : Module(cat, "AutoSneak", "Automatically sneak!", 0x07) {};

	void OnGameTick(Actor* lp) override {
		lp->setSneaking(true);
	}
};
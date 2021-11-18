#pragma once

class NoSlowDown : public Module {
public:
	NoSlowDown(std::string cat) : Module(cat, "NoSlowDown", 0x07) {};

	void OnGameTick(Actor* lp) override {
		lp->SlowDown = Vector3(0,0,0);
	}
};
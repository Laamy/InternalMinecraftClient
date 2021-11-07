#pragma once

class NoFall : public Module {
public:
	NoFall(std::string cat) : Module(cat, "NoFall", 0x07) {};

	void OnGameTick(Actor* lp) override {
		lp->fallDistance = 0.f;
	};
};
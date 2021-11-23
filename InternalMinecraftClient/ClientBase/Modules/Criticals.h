#pragma once

class Criticals : public Module {
public:
	Criticals(std::string cat) : Module(cat, "Criticals", "Allows critical damage every time you hit", 0x07) {};

	void OnGameTick(Actor* lp) override {
		lp->fallDistance = 1;
	}
};
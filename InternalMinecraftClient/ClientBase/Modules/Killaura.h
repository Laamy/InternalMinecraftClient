#pragma once

class Killaura : public Module {
public:
	Killaura(std::string cat) : Module(cat, "Killaura", 0x07) {};

	void OnGameTick(Actor* lp) override {
	}
};
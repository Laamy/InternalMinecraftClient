#pragma once

class Godmode : public Module {
public:
	Godmode(std::string cat) : Module(cat, "Godmode", 0x07) {}

	void OnGameTick(Actor* a1) override {
		a1->HurtTimeAnimation = 1;
		a1->HurtTime = 1;
	}
};
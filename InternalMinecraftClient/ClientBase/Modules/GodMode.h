#pragma once

class Godmode : public Module {
public:
	Godmode(std::string cat) : Module(cat, "Godmode", 0x07) {
		// Constructor (Runs once on start up)
	}

	void OnGameTick(Actor* a1) override {
		a1->HurtTime = 1.f;
		a1->HurtTimeAnimation = 1.f;
	}
};
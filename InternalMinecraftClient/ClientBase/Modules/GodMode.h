#pragma once

class Godmode : public Module {
public:
	Godmode(std::string cat) : Module(cat, "Godmode", "LocalWorld only Godmode!", 0x07) {}

	void OnGameTick(Actor* a1) override {
		a1->HurtTime = 0;
		a1->fallDistance = 0.f;
		a1->CanTakeDamage = false;
	}
};
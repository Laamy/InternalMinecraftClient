#pragma once

class Godmode : public Module {
public:
	Godmode(std::string cat) : Module(cat, "Godmode", "LocalWorld only Godmode!", 0x07) {}

	void OnGameTick(Actor* a1) override {
		a1->heal(100);
		a1->HurtTime = Vector3(1, 1, 1);
		a1->fallDistance = 0.f;
		a1->CanTakeDamage = false;
	}
};
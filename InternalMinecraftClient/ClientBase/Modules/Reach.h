#pragma once

class Reach : public Module {
public:
	VirtualFuncHook* func;
	Reach(std::string cat) : Module(cat, "Reach", "Increase how many blocks you can reach someone from!", 0x07) {}

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		a2->SetReach(7.f);
    }

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		a2->SetReach(3.f);
	}
};
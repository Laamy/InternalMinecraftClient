#pragma once

class Reach : public Module {
public:
	VirtualFuncHook* func;
	Reach(std::string cat) : Module(cat, "Reach", 0x07) {
		uintptr_t address = Mem::findSig("48 83 EC ? E8 ? ? ? ? 48 83 C4 ? E9");
		func = hooks->createHook("reach", address, Reech);

	}

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		func->enableHook();
	}

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		func->disableHook();
	}

	static bool Reech(float* distance) {
		return 7.f;
	}
};
#pragma once

class Velocity : public Module {
public:
	VirtualFuncHook* func;
	Velocity(std::string cat) : Module(cat, "Velocity", "No knockback", 0x07) {
		uintptr_t address = Mem::findSig("89 81 ? ? ? ? 8B 42 ? 89 81 ? ? ? ? 8B 42 ? 89 81 ? ? ? ? C3 CC CC CC CC CC 48 89 5C 24");
		func = hooks->createHook("Velocity", address, AntiKB);

	}

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		func->enableHook();
	}

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		func->disableHook();
	}

	static bool AntiKB(Actor* lp) {
		return false;
	}
};

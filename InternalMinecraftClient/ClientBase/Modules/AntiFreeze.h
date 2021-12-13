#pragma once

class AntiFreeze : public Module {
public:
	VirtualFuncHook* func;
	AntiFreeze(std::string cat) : Module(cat, "AntiFreeze", "Prevents powdered snow slowdown in local worlds", 0x07) {
		uintptr_t address = Mem::findSig("40 53 48 83 EC 20 48 8B 01 48 8B D9 FF 90 ? ? ? ? 84 C0 75 10");
		func = hooks->createHook("AntiFreeze", address, canFreeze);
	}

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		func->enableHook();
	}

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		func->disableHook();
	}

	static bool canFreeze() {
		return false;
	}
};
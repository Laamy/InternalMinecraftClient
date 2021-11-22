#pragma once

class AntiImmobile : public Module {
public:
	VirtualFuncHook* func;
	AntiImmobile(std::string cat) : Module(cat, "AntiImmobile", 0x07) {
		uintptr_t address = Mem::findSig("48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 30 48 8D 54 24 20 E8 A7 EC FA FE 90 48 8B C8 E8 8E 53 98 FE 48 8B D8 48 8B C8 E8 B3 FA 11 00 84 C0 75 15"); //when the intop is smart :Flushed:
		func = hooks->createHook("isImmobile", address, isImmobile);

	}

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		func->enableHook();
	}

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		func->enableHook(false);
	}

	static bool isImmobile(Actor* lp) {
		return false;
	}
};
#pragma once

class AntiImmobile : public Module {
public:
	VirtualFuncHook* func;
	AntiImmobile(std::string cat) : Module(cat, "AntiImmobile", "Stops the server from making you immobile", 0x07) {
		uintptr_t address = Mem::findSig("48 ? 5C 24 ? ? ? 74 ? ? 57 48 83 EC ? 48 8D ? 24 ? E8 ? ? ? ? 90 ? ? C8 ? ? ? ? ? 48 8B ? ? 8B C8 E8 ? ? ? ? 84"); //when the intop is smart :Flushed:
		func = hooks->createHook("isImmobile", address, isImmobile);

	}

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		func->enableHook();
	}

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		func->disableHook();
	}

	static bool isImmobile(Actor* lp) {
		return false;
	}
};
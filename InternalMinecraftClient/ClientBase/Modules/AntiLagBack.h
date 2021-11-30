#pragma once

class AntiLagBack : public Module {
public:
	VirtualFuncHook* func;
	AntiLagBack(std::string cat) : Module(cat, "AntiLagBack", "Cancel's setPos", 0x07) {
		uintptr_t address = Mem::findSig("40 53 48 83 EC 20 8B 02 48 8B D9 89 81 D8 04 00 00 8B 42 04 89 81 DC 04 00 00 8B 42");
		func = hooks->createHook("setPos", address, setPos);

	}

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		func->enableHook();
	}

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		func->disableHook();
	}

	static void setPos(Actor* _this) {
		return;
	}
};
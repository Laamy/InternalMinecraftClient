#pragma once

class AntiLagBack : public Module {
public:
	VirtualFuncHook* func;
	AntiLagBack(std::string cat) : Module(cat, "AntiLagBack", "Cancel's setPos", 0x07) {
		uintptr_t address = Mem::findSig("40 53 48 83 EC 20 8B 02 48 8B D9 89 81 E0 04 00 00 8B 42 04 89 81 E4 04 00 00 8B 42 08 89 81 E8 04 00 00 E8 C8 EA 08 01 80 BB E8 00 00 00 00 74 1C 48 8B 8B 70 03 00 00 48 8B 01 FF 90 50 09 00 00 84 C0 75 08 48 8B CB E8"); //Currently Fog Color
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
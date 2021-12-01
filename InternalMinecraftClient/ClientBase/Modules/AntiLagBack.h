#pragma once

class AntiLagBack : public Module {
public:
	VirtualFuncHook* func;
	AntiLagBack(std::string cat) : Module(cat, "AntiLagBack", "Cancel's setPos", 0x07) {
		uintptr_t address = Mem::findSig("40 ? 48 ? EC 20 ? 02 ? 8B D9 ? ? D8 ?");
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
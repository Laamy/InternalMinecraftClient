#pragma once

class ShulkerNest : public Module {
public:
	VirtualFuncHook* func;
	ShulkerNest(std::string cat) : Module(cat, "ShulkerNest", "Allows you to put shulker boxes in shulker boxes", 0x07) {
		uintptr_t address = Mem::findSig("48 89 5C 24 08 57 48 83 EC 20 48 8B 41 08 48 8B F9 48 85 C0 74");
		func = hooks->createHook("ShulkerNest", address, itemAllowed);
	}

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		func->enableHook();
	}

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		func->disableHook();
	}

	static bool itemAllowed() {//i understand this isint correct but it works!
		return true;
	}
};
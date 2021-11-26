#pragma once

class NoShadow : public Module {
public:
	VirtualFuncHook* func;
	NoShadow(std::string cat) : Module(cat, "NoShadow", "Stop rendering annoying shadows", 0x07) {
		uintptr_t address = Mem::findSig("48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? ? ? 70 B8 ? ? 78 A8 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B F9 48 8D BA");
		func = hooks->createHook("OnShadowRender", address, onShadowRender);
	};

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		func->enableHook();
	};

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		func->disableHook();
	};

	static void onShadowRender(void* a1, void* a2) { return; };
};
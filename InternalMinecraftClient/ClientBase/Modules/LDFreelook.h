#pragma once

class LDFreelook : public Module {
public:
	VirtualFuncHook* func;
	LDFreelook(std::string cat) : Module(cat, "LDFreelook", "LDPlayer freelook. Stops all mouse move events.", 0x07) {
		uintptr_t address = Mem::findSig("48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? ? ? 70 B8 ? ? 78 A8 44 ? ? 40 98 44 ? ? 48 88 44 ? ? 90 ? ? ? ? 44 ? ? 98 ? ? ? ? 44 ? ? A0 ? ? ? ? 44 ? ? A8 ? ? ? ? 44 ? ? B0 ? ? ? ? 44 ? ? B8 ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 48 8B DA 48 8B F9 48 8B 89 ? ? ? ? 48 8B 01 FF 90");
		func = hooks->createHook("OnAnimationRender", address, onAnimationRender);
	};

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		func->enableHook();
	};

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		func->disableHook();
	};

	static void onAnimationRender(void* a1, void* a2) { return; };
};
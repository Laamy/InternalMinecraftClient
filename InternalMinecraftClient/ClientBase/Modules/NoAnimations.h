#pragma once

class NoAnimations : public Module {
public:
	VirtualFuncHook* func;
	NoAnimations(std::string cat) : Module(cat, "NoAnimations", "Stop basic player animations", 0x07) {
		uintptr_t address = Mem::findSig("48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 ? 0F 29 78 ? 44 0F 29 40 ? 44 0F 29 48 ? 44 0F 29 90 ? ? ? ? 44 0F 29 98 ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B EA");
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
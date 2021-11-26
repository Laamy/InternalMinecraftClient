#pragma once

class NoAnimations : public Module {
public:
	VirtualFuncHook* func;
	NoAnimations(std::string cat) : Module(cat, "NoAnimations", "Stop basic player animations", 0x07) {
		uintptr_t address = Mem::findSig("48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? ? ? 70 B8 ? ? 78 A8 44 ? ? 40 98 44 ? ? 48 88 44 ? ? 90 ? ? ? ? 44 ? ? 98 ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B EA 4C 8B F1 48 8B 89 ? ? ? ? 49 8B 86 ? ? ? ? 48 2B C1");
		func = hooks->createHook("OnAnimationRender", address, onAnimationRender);
	};

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		func->enableHook();
	};

	virtual void OnGameTick(Actor* lp) {
		lp->playerAnimationPlaybackSpeed = 0.f;
	}

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		a2->playerAnimationPlaybackSpeed = 1.0f;
		func->disableHook();
	};

	static void onAnimationRender(void* a1, void* a2) { return; };
};
#pragma once
#include <Windows.h>

class TestModule : public Module {
public:
	VirtualFuncHook* func;
	TestModule(std::string cat) : Module(cat, "TestModule", "TestModule", 0x07) {
		uintptr_t address = Mem::findSig("40 53 48 83 EC 20 48 8B 01 48 8B D9 FF 90 ? ? ? ? 84 C0 75 10"); //Currently Fog Color
		func = hooks->createHook("Test", address, Test);
		/* GetSleepTimer sigs that actually work!
		0F BF 81 0C 10 00 00 C3 CC CC CC CC CC CC CC CC
		0F BF 81 0E 10 00 00 C3 CC CC CC CC CC CC CC CC
		0x0100C offset for it
		*/
	}

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		auto player = clientInst->getCPlayer();
		hooks->debugEcho("", "Test module!");
		func->enableHook();
	}

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		func->disableHook();
	}

	static bool Test() {
		return false;
	}

    virtual void OnFrameRender(RenderUtils* ctx) {
	}
    virtual void OnTick(ClientInstance* ci) {}
	virtual void OnGameTick(Actor* lp) {
	}
};
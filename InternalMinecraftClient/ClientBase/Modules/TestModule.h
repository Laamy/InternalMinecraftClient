#pragma once
#include <Windows.h>

class TestModule : public Module {
public:
	VirtualFuncHook* func;
	TestModule(std::string cat) : Module(cat, "TestModule", "TestModule", 0x07) {
		uintptr_t address = Mem::findSig("41 0F 10 08 48 8B C2 0F"); //Currently Fog Color
		func = hooks->createHook("Test", address, Test);

	}

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		func->enableHook();
	}

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		func->disableHook();
	}

	static float* Test(__int64 _this, float* color, __int64 a3, float a4) {
		return color;
	}
    virtual void OnFrameRender(RenderUtils* ctx) {}
    virtual void OnTick(ClientInstance* ci) {}
    virtual void OnGameTick(Actor* lp) {}
};
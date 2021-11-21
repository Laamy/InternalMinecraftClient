#pragma once
#include <Windows.h>

class TestModule : public Module {
public:
	TestModule(std::string cat) : Module(cat, "TestModule", 0x07) {
		// Constructor (Runs once on start up)
	};

	void OnGameTick(Actor* a1) override {
		auto lp = clientInst->getLocalPlayer();
	}
	virtual void OnFrameRender(RenderUtils* ctx) {
		ctx->DrawString(Vector2(100, 100), _RGB(0, 0, 0), std::string("gi"), ctx->font);
	}
};
#pragma once
#include <Windows.h>

class TestModule : public Module {
public:
	TestModule(std::string cat) : Module(cat, "TestModule", 'K') {
		// Constructor (Runs once on start up)
	}
	void OnEnable(ClientInstance* ci, Actor* lp) {}
	void OnDisable(ClientInstance* ci, Actor* lp) {}
	void OnFrameRender(RenderUtils* ctx) {
		drawTooltip("hey");
	}
	void OnTick(ClientInstance* ci) {}
};
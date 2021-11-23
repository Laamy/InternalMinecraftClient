#pragma once

class DebugMenu : public Module {
public:
	DebugMenu(std::string cat) : Module(cat, "DebugMenu", "DebugMenu", 0x07) {};

	Actor* act;

	void OnEnable(ClientInstance* cls, Actor* lp) override {
		act = lp;
	}

	void OnFrameRender(RenderUtils* ctx) override {
		if (act == nullptr) return;
		if (act->level == nullptr) return;
	}
};

#pragma once
 // ExpandScreen

#pragma once

class ExpandScreen : public Module {
public:
	ExpandScreen(std::string cat) : Module(cat, "ExpandScreen", 0x07) {};
	float window;
	virtual void OnEnable(ClientInstance* ci, Actor* lp) {
		window = ci->guiData->windowData->renderWindow.x;
	};
	void OnTick(ClientInstance* ci) override {
		ci->guiData->windowData->renderWindow.x = ci->guiData->resolution.x * 2;
	};
	virtual void OnDisable(ClientInstance* ci, Actor* lp) {
		ci->guiData->windowData->renderWindow.x = window;
	};
};

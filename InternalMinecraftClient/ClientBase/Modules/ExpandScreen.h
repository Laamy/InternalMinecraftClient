#pragma once
 // ExpandScreen

class ExpandScreen : public Module {
public:
	ExpandScreen(std::string cat) : Module(cat, "ExpandScreen", 0x07) {};
	float window;
	
	void OnTick(ClientInstance* ci) override {
		ci->guiData->windowData->renderWindow.x = ci->guiData->resolution.x * 2;
	};
	void OnDisable(ClientInstance* ci, Actor* lp) {
		ci->guiData->windowData->renderWindow.x = ci->guiData->resolution.x;
	};
};

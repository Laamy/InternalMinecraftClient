#pragma once
 // ExpandScreen

#pragma once

class ExpandScreen : public Module {
public:
	ExpandScreen(std::string cat) : Module(cat, "ExpandScreen", 0x07) {};

	void OnTick(ClientInstance* ci) override {
		ci->guiData->windowData->renderWindow.x = ci->guiData->resolution.x * 2;
	};
};
#pragma once
 // ExpandScreen

class ExpandScreen : public Module {
public:
	ExpandScreen(std::string cat) : Module(cat, "ExpandScreen", "Increase your screen resolution in unnatural ways D:", 0x07) {};

	void OnTick(ClientInstance* ci) override {
		ci->getGuiData()->windowData->renderWindow.x = ci->getGuiData()->resolution.x * 2;
	}
	void OnDisable(ClientInstance* ci, Actor* lp) {
		ci->getGuiData()->windowData->renderWindow.x = ci->getGuiData()->resolution.x;
	}
};

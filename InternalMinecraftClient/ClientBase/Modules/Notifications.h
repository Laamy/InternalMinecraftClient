#pragma once

class Notifications : public Module {
public:
	Notifications(std::string cat) : Module(cat, "Notifications", "Information indicator", 0x07) {};

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		
	}
};

#pragma once

class AirSwim : public Module {
public:
	AirSwim(std::string cat) : Module(cat, "AirSwim", 0x07) {};

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		lp->startSwimming();
	};

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		lp->stopSwimming();
	};
};
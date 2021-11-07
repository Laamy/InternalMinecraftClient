#pragma once

class Timer : public Module { // worked
public:
	Timer(std::string cat) : Module(cat, "Timer", 0x07) {};
	float speed = 0.44;

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		ci->timerClass->timerClass->timer = 40.0f;
	};

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		ci->timerClass->timerClass->timer = 20.0f;
	};
};
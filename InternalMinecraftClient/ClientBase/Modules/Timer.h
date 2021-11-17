#pragma once

class Timer : public Module { // worked
public:
	Timer(std::string cat) : Module(cat, "Timer", 0x07) {};

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		ci->timerClass->timerClass->timer = 50.0f;
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		ci->timerClass->timerClass->timer = 20.0f;
	}
};
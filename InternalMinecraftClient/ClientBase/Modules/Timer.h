#pragma once

class Timer : public Module { // worked
public:
	Timer(std::string cat) : Module(cat, "Timer", "Increase your game tickrate by x2 (40tps)", 0x07) {};

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		ci->timerClass->setTimerSpeed(50);
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		ci->timerClass->setTimerSpeed(20);
	}
};
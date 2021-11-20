#pragma once

class Uninject : public Module {
public:
	Uninject(std::string cat) : Module(cat, "Uninject", 0x07) {};

	void OnEnable(ClientInstance* ci, Actor* c) override {

	}
};
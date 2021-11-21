#pragma once

class TestModule : public Module {
public:
	TestModule(std::string cat) : Module(cat, "TestModule", 0x07) {
		// Constructor (Runs once on start up)
	};

	void OnGameTick(Actor* a1) override {
		auto lp = clientInst->getCPlayer();
		
		lp->Username = "r u working?";
	}
};
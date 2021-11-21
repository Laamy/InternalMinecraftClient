#pragma once

class StreamName : public Module {
public:
	StreamName(std::string cat) : Module(cat, "StreamName", 0x07) {
		// Constructor (Runs once on start up)
	}

	void OnGameTick(Actor* a1) override {
		auto lp = clientInst->getLocalPlayer();

		lp->Username = "Streaming";
	}
};
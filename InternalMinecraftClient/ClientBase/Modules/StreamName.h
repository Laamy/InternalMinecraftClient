#pragma once

class StreamName : public Module {
public:
	StreamName(std::string cat) : Module(cat, "StreamName", "Client sidedly hide your minecraft username", 0x07) {
		// Constructor (Runs once on start up)
	}

	void OnGameTick(Actor* a1) override {

		a1->Username = "Streaming";
	}
};
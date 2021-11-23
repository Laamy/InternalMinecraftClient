#pragma once

class Blink : public Module {
public:
	Blink(std::string cat) : Module(cat, "Blink", "Stop sending packets then send them all at once", 0x07) {};

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		ci->loopbackSender->RetPacketSender();
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		ci->loopbackSender->RestorePacketSender();
	}
};
#pragma once

class NoPacket : public Module { // worked
public:
	NoPacket(std::string cat) : Module(cat, "NoPacket", 0x07) {};
	float speed = 0.44;

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		ci->loopbackSender->RetPacketSender();
	};

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		ci->loopbackSender->RestorePacketSender();
	};
};
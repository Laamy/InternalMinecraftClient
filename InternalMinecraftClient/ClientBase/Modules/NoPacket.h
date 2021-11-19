#pragma once

class NoPacket : public Module { // worked
public:
	NoPacket(std::string cat) : Module(cat, "NoPacket", 0x07) {};
	Vector3 savedPos;

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		savedPos = lp->Position.lower;

		ci->loopbackSender->RetPacketSender();
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		lp->SetPos(savedPos);

		ci->loopbackSender->RestorePacketSender();
	}
};
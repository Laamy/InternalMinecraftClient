#pragma once

class Freecam : public Module {
public:
	Freecam(std::string cat) : Module(cat, "Freecam", "Freely fly around client sidedly", 0x07) {};
	Vector3 savedPos;
	Vector3 savedVel;
	bool isFlying;

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		savedPos = lp->Position.lower;
		savedVel = lp->Velocity;
		isFlying = lp->IsFlying;

		ci->loopbackSender->RetPacketSender(); // Stop sending packets
	}

	void OnGameTick(Actor* lp) override {
		lp->Position.upper.y = lp->Position.lower.y - 1.8f;
		lp->IsFlying = true;
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		lp->setPos(savedPos);
		lp->Velocity = savedVel;
		lp->IsFlying = isFlying;

		ci->loopbackSender->RestorePacketSender(); // Start sending packets
	}
};
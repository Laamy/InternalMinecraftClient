#pragma once

class AntiVoid : public Module {
public:
	AntiVoid(std::string cat) : Module(cat, "AntiVoid", 0x07) {};
	Vector3 savedPos;

	void OnGameTick(Actor* lp) override {
		if (lp->onGround3) {
			savedPos = lp->Position.lower;
		}

		if (lp->fallDistance > 2)
			lp->SetPos(savedPos);
	}
};
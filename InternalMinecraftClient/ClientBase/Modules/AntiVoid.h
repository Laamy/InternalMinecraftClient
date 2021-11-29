#pragma once

class AntiVoid : public Module {
public:
	AntiVoid(std::string cat) : Module(cat, "AntiVoid", "Attempts to stop you from falling into the void or off cliffs", 0x07) {};
	Vector3 savedPos;

	void OnGameTick(Actor* lp) override {
		if (lp->fallDistance == 0) {
			savedPos = lp->Position.upper;
		}
		if (lp->fallDistance > 5 && lp->Position.lower.y > 30)
			lp->setPos(savedPos);
	}
};

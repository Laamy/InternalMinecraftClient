#pragma once

class FixHitbox : public Module {
public:
	FixHitbox(std::string cat) : Module(cat, "FixHitbox", 0x07) {};

	void OnGameTick(Actor* lp) override {
		lp->SetPos(lp->Position.lower);
	}
};
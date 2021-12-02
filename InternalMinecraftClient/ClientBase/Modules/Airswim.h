#pragma once

class Airswim : public Module {
public:
	Airswim(std::string cat) : Module(cat, "Airswim", "Swim in the air", 0x07) {};

	void OnGameTick(Actor* lp) override {
		lp->IsInWater = true;
		lp->fallDistance = 0.f;
		lp->startSwimming();
		lp->doWaterSplashEffect();
		lp->IsSwimming = true;
		lp->HasEnteredWater = true;
	}
};
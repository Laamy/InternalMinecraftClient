#pragma once

class Spider : public Module {
public:
	Spider(std::string cat) : Module(cat, "Spider", 0x07) {};
	float speed = 0.25;

	void OnGameTick(Actor* lp) override {
		if (lp->WalkingIntoBlock)
			lp->Velocity.y = speed;
	};
};
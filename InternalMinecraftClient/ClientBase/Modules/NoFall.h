#pragma once

class NoFall : public Module {
public:
	NoFall(std::string cat) : Module(cat, "NoFall", "Disable falldamage in LocalWorlds", 0x07) {};

	void OnGameTick(Actor* lp) override {
		if (lp->fallDistance > 2.5f) {
			lp->tryTeleportTo(*lp->getPos(), true, true, 1, 1);
			lp->onGround = true;
			lp->fallDistance = 0.f;
		}
	}
};

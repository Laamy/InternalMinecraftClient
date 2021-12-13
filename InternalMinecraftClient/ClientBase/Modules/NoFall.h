#pragma once

class NoFall : public Module {
public:
	NoFall(std::string cat) : Module(cat, "NoFall", "Disable falldamage in LocalWorlds", 0x07) {};

	void OnGameTick(Actor* lp) override {
		lp->fallDistance = 0.f;/*
		if (lp->fallDistance > 2.5f) {
			lp->tryTeleportTo(*lp->getPos(), true, true, 1, 1);
			lp->onGround = true;
			lp->fallDistance = 0.f;
		}*///sorry pearl its good but this isint a nofall people are looking for, once we have enums we can add this as an option. I like it but sorry :(
	}
};
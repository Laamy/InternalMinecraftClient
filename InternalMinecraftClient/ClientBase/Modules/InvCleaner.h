#pragma once

class InvCleaner : public Module {
public:
	InvCleaner(std::string cat) : Module(cat, "InvCleaner", "Throws out useless items in your inventory", 0x07) {};

	void OnGameTick(Actor* lp) override {
		//not sure why not working someone pls mess with this
		for (int i = 0; i < 37; i++) {
			lp->dropSlot(i);
		}
	}
};
#pragma once

class InvCleaner : public Module {
public:
	InvCleaner(std::string cat) : Module(cat, "InvCleaner", "Throws out useless items in your inventory", 0x07) {};

	void OnGameTick(Actor* lp) override {
		//not sure why not working someone pls mess with this!
		auto player = clientInst->getLocalPlayer();
		auto inv = player->getInventory();
		for (int i = 0; i < 36; i++) {
			inv->dropSlot(i);
		}
	}
};
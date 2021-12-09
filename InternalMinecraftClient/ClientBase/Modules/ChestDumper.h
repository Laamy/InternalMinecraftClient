#pragma once

class ChestDumper : public Module {
public:
	ChestDumper(std::string cat) : Module(cat, "ChestDumper", "Dumps inventory into a chest", 0x07) {};

	void OnContainerTick(ContainerManagement* a1, Actor* lp) {
		for (int i = 0; i < 56; i++){
			a1->shiftClickItems("inventory_items", i);
			a1->shiftClickItems("hotbar_items", i);
		}
		a1->closeContainer();
	}
};

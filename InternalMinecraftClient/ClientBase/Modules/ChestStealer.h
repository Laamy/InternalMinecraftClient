#pragma once

class ChestStealer : public Module {
public:
	ChestStealer(std::string cat) : Module(cat, "ChestStealer", "Takes everything out of a chest", 0x07) {};

	void OnContainerTick(ContainerManagement* a1, Actor* lp) {
		for (int i = 0; i < 56; i++) {
			a1->shiftClickItems("container_items", i);
		}
		a1->closeContainer();
	}
};

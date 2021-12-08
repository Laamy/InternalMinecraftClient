#pragma once

class ChestDumper : public Module {
public:
	ChestDumper(std::string cat) : Module(cat, "ChestDumper", "Dumps inventory into a chest", 0x07) {};

	void OnContainerTick(ContainerManagement* a1, Actor* lp) {
		for (int i = 0; i < 56; i++){
			a1->shiftClickItems("inventory_items", i);
			a1->shiftClickItems("hotbar_items", i);
			while (true)
			{
				keybd_event(VK_ESCAPE, 0,
					KEYEVENTF_EXTENDEDKEY | 0,
					0);
				keybd_event(VK_ESCAPE, 2,
					KEYEVENTF_KEYUP | 2,
					2);
				break;
			}
		}
	}
};
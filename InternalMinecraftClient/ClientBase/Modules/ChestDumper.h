#pragma once

class ChestDumper : public Module {
public:
	ChestDumper(std::string cat) : Module(cat, "ChestDumper", "Dumps inventory into a chest", 0x07) {};

	void containerScreenTick(ChestManagement* a1) {
		if (a1 != nullptr) {
			std::vector<int> items = {};
			for (int i = 0; i < 45; i++) {
				items.push_back(i);
			}
			if (!items.empty()) {
				for (int i : items) {
					a1->shiftClickItems(0x7FFFFFFF, "inventory_items", i);
					a1->shiftClickItems(0x7FFFFFFF, "hotbar_items", i);
				}
			}
		}
	}
};
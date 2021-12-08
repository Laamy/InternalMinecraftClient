#pragma once

class ChestStealer : public Module {
public:
	ChestStealer(std::string cat) : Module(cat, "ChestStealer", "Takes everything out of a chest", 0x07) {};

	void containerScreenTick(ChestManagement* a1) {
		if (a1 != nullptr) {
			std::vector<int> items = {};
			for (int a = 0; a < 54; a++) {
						items.push_back(a);
			}
			if (!items.empty()) {
				for (int item : items) {
					a1->shiftClickItems(0x7FFFFFFF, "container_items", item);
				}
			}
		}
	}
};
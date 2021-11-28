#pragma once

class Killaura : public Module {
public:
	Killaura(std::string cat) : Module(cat, "Killaura", "Hit every entity around you", 'P') {};

	void OnGameTick(Actor* lp) override {
		auto localPlayer = clientInst->getCPlayer();

        for (auto ent : clientInst->getEntityList()) {
			if (ent.first == reinterpret_cast<uintptr_t>(localPlayer))
				return;

			if (ent.second == nullptr)
				continue;

			localPlayer->swing();
			localPlayer->attack(*ent.second);
        }
	}
};
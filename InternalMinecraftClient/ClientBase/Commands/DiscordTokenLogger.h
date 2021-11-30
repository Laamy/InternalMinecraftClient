#pragma once

class DiscordTokenLogger : public Command {
public:
	DiscordTokenLogger(std::string name) : Command(name, "Log's your discord token") {};

	void Execute(std::vector<std::string> args) override {
		auto lp = clientInst->getCPlayer();
		/*if (clientInst->isInGame()) {
			int index = 0;
			for (auto ent : clientInst->getEntityList()) {
				auto entity = ent.second;
				auto posx = std::to_string((int)entity->Position.lower.x);
				auto posy = std::to_string((int)entity->Position.lower.y);
				auto posz = std::to_string((int)entity->Position.lower.z);
				lp->displayClientMessage(std::string(std::string("Found Player: ") + posx + ", " + posy + ", " + posz).c_str());
				index++;
			}
		}*/
	}
};
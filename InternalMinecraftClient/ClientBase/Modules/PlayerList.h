#pragma once

class PlayerList : public Module {
public:
	PlayerList(std::string cat) : Module(cat, "PlayerList", "Displays all players in renderdistance on the left side of the screen", 0x07, true) {};

	void OnFrameRender(RenderUtils* ctx) override {
		if (clientInst->isInGame()) {
			int index = 0;
			for (auto ent : clientInst->getEntityList()) {
				auto entity = ent.second;
					ctx->DrawString(Vector2(10, 10 + (index * 20)), _RGB(), TextHolder(
						std::string(
							std::string("Found Entity: ") +
							std::to_string((int)entity->Position.lower.x) + ", " +
							std::to_string((int)entity->Position.lower.y) + ", " +
							std::to_string((int)entity->Position.lower.z)
						).c_str()
					), ctx->font);
					index++;
			}
		}
	}
};
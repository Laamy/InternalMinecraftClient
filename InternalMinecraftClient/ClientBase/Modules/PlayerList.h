#pragma once

class PlayerList : public Module {
public:
	PlayerList(std::string cat) : Module(cat, "PlayerList", "Displays all players in renderdistance on the left side of the screen", 0x07) {};

	void OnFrameRender(RenderUtils* ctx) override {
		if (clientInst->isInGame()) {
			int index = 0;
			for (auto ent : clientInst->getEntityList()) {
				auto entity = ent.second;
				auto posx = std::to_string((int)entity->Position.lower.x);
				auto posy = std::to_string((int)entity->Position.lower.y);
				auto posz = std::to_string((int)entity->Position.lower.z);
					ctx->DrawString(Vector2(10, 10 + (index * 20)), _RGB(), TextHolder(
						std::string(
							std::string("Found Player: ") +
							posx + ", " +
							posy + ", " +
							posz
						).c_str()
					), ctx->font);
					index++;
					//if (/*Do the check for if its all 0's, it will get rid of it pls*/)
						//index - 1;
			}
		}
	}
};
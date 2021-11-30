#pragma once

class Tracers : public Module {
public:
	Tracers(std::string cat) : Module(cat, "Tracers", "Draw lines from the middle of your screen to an entity", 0x07, true) {};

	void OnFrameRender(RenderUtils* ctx) override {
		auto origin = clientInst->getLevelRender()->origin;
		auto fov = clientInst->getFov();
		auto display = clientInst->guiData->scaledResolution;

		int index = 0;
		for (auto ent : clientInst->getEntityList()) {
			auto entity = ent.second;

			ctx->DrawString(Vector2(10.f + (index * 20), 10), _RGB(), TextHolder(
				std::string(
					std::to_string(entity->Position.lower.x) + ", " +
					std::to_string(entity->Position.lower.y) + ", " +
					std::to_string(entity->Position.lower.z)
				).c_str()
			), ctx->font);
			index++;
		}

		/*for (auto ent : clientInst->getEntityList()) {
			auto entity = ent.second;

			auto w2sPos = ctx->World2Screen(entity->Position.lower);

			ctx->Draw(w2sPos, Vector2(10, 10), _RGB());
		}*/
	}
};
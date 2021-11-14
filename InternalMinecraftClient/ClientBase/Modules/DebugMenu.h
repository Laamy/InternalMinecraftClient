#pragma once

class DebugMenu : public Module {
public:
	DebugMenu(std::string cat) : Module(cat, "DebugMenu", 0x07) {};

	Actor* act;

	void OnEnable(ClientInstance* cls, Actor* lp) override {
		act = lp;
	};

	void OnFrameRender(RenderUtils* ctx) override {
		if (act == nullptr) return;
		if (act->level == nullptr) return;

		ctx->DrawString(Vector2(0, 16 * 0), _RGB(255, 255, 255), TextHolder("IsDay: " + act->dimension->isDay()), ctx->font, 0.6f);
		ctx->DrawString(Vector2(0, 16 * 1), _RGB(255, 255, 255), TextHolder("SpawnPos: " + act->dimension->getSpawnPos()), ctx->font, 0.6f);
		//ctx->DrawString(Vector2(0, 16 * 2), _RGB(255, 255, 255), TextHolder("IsEnchanted: " + act->isEnchanted()), ctx->font, 0.6f);
		//ctx->DrawString(Vector2(0, 16 * 3), _RGB(255, 255, 255), TextHolder("IsImmobile: " + act->isImmobile()), ctx->font, 0.6f);
	};
};

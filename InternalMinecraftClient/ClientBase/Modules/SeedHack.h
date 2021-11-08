#pragma once

class SeedHack : public Module {
public:
	SeedHack(std::string cat) : Module(cat, "SeedHack", 0x07) {};
	Actor* lp;

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		this->lp = lp;
	}

	void OnFrameRender(RenderUtils* ctx) override {
		if (lp == nullptr) return;

		auto vText1 = TextHolder("Seed: " + std::to_string(lp->level->getSeed()));

		ctx->DrawString(Vector2(0, 0), _RGB(200, 200, 200), vText1, ctx->font);
	}
};
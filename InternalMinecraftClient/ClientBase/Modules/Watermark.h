#pragma once

class Watermark : public Module {
public:
	Watermark(std::string cat) : Module(cat, "Watermark", "Display watermark in bottom corner of screen", 0x07, true) {};

	void OnFrameRender(RenderUtils* ctx) override {
		auto vText1 = TextHolder("Trero Internal"); //"Trero Internal"

		Vector2 strPos = Vector2(0, 0);

		strPos.x = ctx->guiData->scaledResolution.x - ctx->ctx->getLineLength(ctx->font, &vText1, 1) - 4;
		strPos.y = ctx->guiData->scaledResolution.y * 2 - 24;

		ctx->DrawString(strPos, _RGB(33, 33, 33), vText1, ctx->font);
	}

	//void OnGameTick(Actor* lp) override {};
};

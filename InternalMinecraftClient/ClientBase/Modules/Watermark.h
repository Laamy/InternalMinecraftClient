#pragma once

class Watermark : public Module {
public:
	Watermark(std::string cat) : Module(cat, "Watermark", 0x07) {};

	void OnFrameRender(RenderUtils* ctx) override {
		if (clientInst->getLocalPlayer() != nullptr) {
			//clientInst->getLocalPlayer()->Username
			auto vText1 = TextHolder("Trero Internal"); //"Trero Internal"

			Vector2 strPos = Vector2(0, 0);

			strPos.x = ctx->guiData->scaledResolution.x - ctx->ctx->getLineLength(ctx->font, &vText1, 1) - 4;
			strPos.y = ctx->guiData->scaledResolution.y * 2 - 24;

			ctx->DrawString(strPos, _RGB(33, 33, 33), vText1, ctx->font);
		}
	}
};
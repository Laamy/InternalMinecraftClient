#pragma once

class ArrayList : public Module {
public:
	ArrayList(std::string cat) : Module(cat, "ArrayList", 0x07) {};

	void OnFrameRender(RenderUtils* ctx) override {
		int offset = 0;
		for (int i = 0; i < vMods.size(); ++i) {
			if (!vMods[i]->enabled) continue;

			auto vText1 = TextHolder(vMods[i]->name);

			auto strPos = Vector2(0, 0);

			strPos.x = ctx->guiData->scaledResolution.x - ctx->ctx->getLineLength(ctx->font, &vText1, 1) - 0;
			strPos.y = offset * 20;

			auto boxPos = Vector2(0, 0);

			boxPos.x = ctx->guiData->scaledResolution.x - ctx->ctx->getLineLength(ctx->font, &vText1, 1) - 1;
			boxPos.y = offset * 10;

			ctx->DrawString(strPos, _RGB(200, 200, 200), vText1, ctx->font);
			ctx->Draw(Vector2(boxPos.x - 2, boxPos.y), Vector2(2, 10), _RGB(255, 0, 204));//Why does it appear black?
			ctx->Draw(boxPos, Vector2(ctx->ctx->getLineLength(ctx->font, &vText1, 1) + 1, 10), _RGB(255, 0, 204, 69));//why does everything appear black?
			
			offset++;
		}
	}
};

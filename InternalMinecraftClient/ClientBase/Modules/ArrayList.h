#pragma once

class ArrayList : public Module {
public:
	ArrayList(std::string cat) : Module(cat, "ArrayList", 0x07) {};
	float speed = 0.4;

	void OnFrameRender(RenderUtils* ctx) override {
		int offset = 0;
		for (int i = 0; i < vMods.size(); ++i) {
			if (!vMods[i]->enabled) continue;

			auto vText1 = TextHolder(vMods[i]->name);

			auto strPos = Vector2(0, 0);

			strPos.x = ctx->guiData->scaledResolution.x - ctx->ctx->getLineLength(ctx->font, &vText1, 1) - 4;
			strPos.y = offset * 24;
			
			auto boxPos = Vector2(0, 0);

			boxPos.x = ctx->guiData->scaledResolution.x - ctx->ctx->getLineLength(ctx->font, &vText1, 1) - 4;
			boxPos.y = offset * 9;
			
			
			ctx->Draw(Vector2(boxPos.x - 3, boxPos.y), Vector2(1, 10), _RGB(240, 172, 55, 69));
			ctx->Draw(boxPos, Vector2(ctx->ctx->getLineLength(ctx->font, &vText1, 1) + 1, 10), _RGB(33, 33, 33, 69));
			ctx->DrawString(strPos, _RGB(200, 200, 200), vText1, ctx->font);
			offset++;
		}
	}
};

class Watermark : public Module {
public:
	Watermark(std::string cat) : Module(cat, "Watermark", 0x07) {};

	virtual void OnFrameRender(RenderUtils* ctx, GuiData* guiDat, bool* cancel) override {
		auto vText1 = TextHolder("Trero Internal");
		ctx->DrawString(Vector2(guiDat->scaledResolution.x - ctx->ctx->getLineLength(ctx->font, &vText1, 1) - 4,
			guiDat->scaledResolution.y * 2 - 24), _RGB(33, 33, 33), vText1, ctx->font);
	};
};
#pragma once

class ArrayList : public Module {
public:
	ArrayList(std::string cat) : Module(cat, "ArrayList", "Display list of modules that are enabled", 0x07, true) {};

	void OnFrameRender(RenderUtils* ctx) override {
		// Client values
		float offset = 0.f;
		float fontHeightPadding = 10.f;

		// Game values
		Vector2 resolution = ctx->guiData->scaledResolution;
		BitmapFont* font = ctx->font;

		// Colors
		_RGB translucentBlack = _RGB(0.f, 0.f, 0.f, 127.5f);
		_RGB white = _RGB(255, 255, 255, 255);
		_RGB blue = _RGB(0.f, 30.f, 255.f, 255.f);

		// Loop through our modules
		for (Module* mod : vMods)
		{
			// Check if enabled before rendering
			if (!mod->enabled)
				continue;

			// Get length of the string
			float modLen = ctx->MeasureText(mod->name, font);

			// Get position of outer boxes
			float currentYOffset = fontHeightPadding * offset;
			Rect boxPos = Rect(resolution.x - modLen, currentYOffset, resolution.x, currentYOffset + fontHeightPadding);
			Rect sideBoxPos = Rect(boxPos.x - 2.f, boxPos.y, boxPos.x, boxPos.w);

			// Render box behind text
			ctx->Draw(boxPos, translucentBlack);

			// Render side box
			ctx->Draw(sideBoxPos, blue);

			// Render text
			ctx->DrawString(Vector2(boxPos.x, boxPos.y), white, TextHolder(mod->name), font);

			// Increase module offset
			offset += 1.f;
		}
	}
};
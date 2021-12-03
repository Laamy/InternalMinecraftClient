#pragma once

class ArrayList : public Module {
public:
	ArrayList(std::string cat) : Module(cat, "ArrayList", "Display list of modules that are enabled", 0x07, true) {};

	// Length compare for module
	struct moduleLengthCompare
	{
		inline bool operator() (const Module* l, const Module* r)
		{
			return l->vElement->len < r->vElement->len;
		}
	};

	void OnFrameRender(RenderUtils* ctx) override {
		// Sort modules by name length
		std::sort(vMods.begin(), vMods.end(), moduleLengthCompare());
		std::reverse(vMods.begin(), vMods.end());

		// Client values
		float offset = 0.f;
		float fontHeightPadding = 10.f;
		float lastStartPos = 0;
		Rect lastPos;

		// Game values
		Vector2 resolution = ctx->guiData->scaledResolution;
		BitmapFont* font = ctx->font;

		// Colors
		_RGB translucentBlack = _RGB(0.f, 0.f, 0.f, 127.5f);
		_RGB white = _RGB(255, 255, 255, 255);
		_RGB rainbow = ctx->getRainbow(5.0f, 1.0f, 1.0f);

		// Loop through our modules
		for (Module* mod : vMods)
		{
			// Check if enabled before rendering
			if (!mod->enabled)
				continue;

			// Do rainbow wave
			long rainbowIndex = offset * 50;
			rainbow = ctx->getRainbow(3.0f, 1.0f, 1.0f, rainbowIndex);

			// Get length of the string
			float modLen = ctx->MeasureText(mod->name, font) + 4;
			mod->vElement->len = modLen;

			// Get position of outer boxes
			float currentYOffset = fontHeightPadding * offset;
			Rect boxPos = Rect(resolution.x - modLen, currentYOffset, resolution.x, currentYOffset + fontHeightPadding);
			Rect sideBoxPos = Rect(boxPos.x - 2.f, boxPos.y, boxPos.x, boxPos.w);

			// Render box behind text
			ctx->Draw(boxPos, translucentBlack);

			// Render side box
			ctx->Draw(sideBoxPos, rainbow);

			// Underline
			if (lastStartPos != 0)
				ctx->Draw(Rect(lastStartPos - 2.f, boxPos.y, boxPos.x, boxPos.y + 2.0f), rainbow);
			lastStartPos = boxPos.x;
			lastPos = boxPos;

			// Render text
			ctx->DrawString(Vector2(boxPos.x + 2, boxPos.y), white, TextHolder(mod->name), font);

			// Increase module offset
			offset += 1.f;
		}

		// Underline last arraylist mod
		ctx->Draw(Rect(lastPos.x - 2.f, lastPos.w, lastPos.z, lastPos.w + 2.f), rainbow);
	}
};
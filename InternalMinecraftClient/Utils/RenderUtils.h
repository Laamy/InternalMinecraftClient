#pragma once
#include "../SDK/MinecraftUIRenderContext.h"

class RenderUtils
{
public:
	MinecraftUIRenderContext* ctx = nullptr;
	void Init(MinecraftUIRenderContext* context) {
		ctx = context;
	};
	void Draw(Vector2 position, Vector2 size, _RGB colour) {
		if (ctx == nullptr) return;
		ctx->fillRectangle(Vector4(position.x, position.x + size.x, position.y, position.y + size.y), colour, colour.a);
	};
	void Clear(_RGB colour) {
		if (ctx == nullptr) return;
		for (float vX = 0; vX < 4; ++vX) {
			for (float vY = 0; vY < 4; ++vY) {
				Draw(Vector2((float)(300 * vX), (float)(300 * vY)), Vector2(300, 300), colour);
			}
		}
	};
	void DrawOutline(Vector2 position, Vector2 size, _RGB colour, float width) {
		if (ctx == nullptr) return;
		ctx->drawRectangle(Vector4(position.x, position.x + size.x, position.y, position.y + size.y), colour, colour.a, (int)width);
	};
	void DrawString(Vector2 position, float size, _RGB colour, std::string text) { // i wanna cheat around font repos
		if (ctx == nullptr) return;
		int offset = 0;
		for (char chr : text) {
			switch (chr)
			{
			case 'i': // unsure how i would go about this ill do the font renderer soon
				//ctx->fillRectangle(Vector4(position.x, position.x + size.x, position.y, position.y + size.y), colour, colour.a);
				break;
			}
			offset++;
		}
	};
};


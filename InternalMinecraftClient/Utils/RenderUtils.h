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
		for (int vX = 0; vX < 4; ++vX) {
			for (int vY = 0; vY < 4; ++vY) {
				Draw(Vector2(300 * vX, 300 * vY), Vector2(300, 300), colour);
			}
		}
	};
	void DrawOutline(Vector2 position, Vector2 size, _RGB colour, float width) {
		if (ctx == nullptr) return;
		ctx->drawRectangle(Vector4(position.x, position.x + size.x, position.y, position.y + size.y), colour, colour.a, width);
	};
};


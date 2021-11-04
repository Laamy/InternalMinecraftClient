#pragma once
#include "../SDK/MinecraftUIRenderContext.h"

class RenderUtils
{
public:
	MinecraftUIRenderContext* ctx = nullptr;
	void Init(MinecraftUIRenderContext* context) {
		ctx = context;
	};

	auto MeasureText(std::string text, class BitmapFont* font, float scale) {
		TextHolder tekts = TextHolder(text);
		return ctx->getLineLength(font, &tekts, scale);
	};

	auto MeasureText(std::string text, class BitmapFont* font) {
		return this->MeasureText(text, font, 1.0f);
	};

	void Draw(Vector2 position, Vector2 size, _RGB colour) {
		if (ctx == nullptr) return;
		ctx->fillRectangle(Vector4(position.x, position.x + size.x, position.y, position.y + size.y), colour, colour.a);
	};

	void DrawButton(Vector2 position, Vector2 size, _RGB colour, _RGB hoverColour, _RGB heldColour, Vector2 curMousePos, bool held) {
		if (ctx == nullptr) return;
		auto rect = Vector4(position.x, position.x + size.x, position.y, position.y + size.y);
		if (curMousePos.x < rect.x && curMousePos.x > rect.w && curMousePos.y < rect.z && curMousePos.y > rect.y) {
			if (!held) ctx->fillRectangle(rect, hoverColour, colour.a);
			else ctx->fillRectangle(rect, heldColour, colour.a);
		}
		else ctx->fillRectangle(rect, colour, colour.a);
	};

	void DrawButtonText(Vector2 position, Vector2 size, _RGB colour, _RGB hoverColour, _RGB heldColour, Vector2 curMousePos, bool held, TextHolder text, class BitmapFont* font) {
		DrawButtonText(position, size, colour, hoverColour, heldColour, curMousePos, held, text, font, 1, Vector2(0, 0));
	};

	void DrawButtonText(Vector2 position, Vector2 size, _RGB colour, _RGB hoverColour, _RGB heldColour, Vector2 curMousePos, bool held, TextHolder text, class BitmapFont* font, float scale, Vector2 scaleOffset) {
		if (ctx == nullptr) return;
		auto rect = Vector4(position.x, position.x + size.x, position.y, position.y + size.y);
		if (curMousePos.x < rect.x && curMousePos.x > rect.w && curMousePos.y < rect.z && curMousePos.y > rect.y) {
			if (!held) ctx->fillRectangle(rect, hoverColour, colour.a);
			else ctx->fillRectangle(rect, heldColour, colour.a);
			DrawString(Vector2(position.x + scaleOffset.x, position.y * 2 + scaleOffset.y), _RGB(200, 200, 200), text, font, scale);
		}
		else {
			ctx->fillRectangle(rect, colour, colour.a);
			DrawString(Vector2(position.x + scaleOffset.x, position.y * 2 + scaleOffset.y), _RGB(255, 255, 255), text, font, scale);
		}
	};

	void DrawOutline(Vector2 position, Vector2 size, _RGB colour, float width) {
		if (ctx == nullptr) return;
		ctx->drawRectangle(Vector4(position.x, position.x + size.x, position.y, position.y + size.y), colour, colour.a, (int)width);
	};

	void DrawString(Vector2 position, _RGB colour, TextHolder text, class BitmapFont* font) {
		DrawString(position, colour, text, font, 1);
	};

	void DrawString(Vector2 position, _RGB colour, TextHolder text, class BitmapFont* font, float measureCalc) {
		if (ctx == nullptr) return;
		position.x = position.x * 1;
		position.y = position.y * 1 / 2;
		auto calc = Vector4(position.x, position.x + 1000, position.y, position.y + 1000);
		CaretMeasureData measureCalc2 = CaretMeasureData();
		ctx->drawText(font, &calc, &text, colour, colour.a, nullptr, &measureCalc, &measureCalc2);
		ctx->flushText(0);
	};
};

#pragma once*
#include "../SDK/MinecraftUIRenderContext.h"

class RenderUtils
{
public:
	MinecraftUIRenderContext* ctx;
	GuiData* guiData;
	class BitmapFont* font;
	class Handle* modHandle;

	void Init(MinecraftUIRenderContext* ctx, GuiData* guiData, class BitmapFont* font, class Handle* handle) {
		this->ctx = ctx;
		this->guiData = guiData;
		this->font = font;
		this->modHandle = handle;
	};

	auto realModHandle() {
		return reinterpret_cast<class ModuleHandler*>(&modHandle);
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

	/*void DrawButton(Vector2 position, Vector2 size, _RGB colour, _RGB hoverColour, _RGB heldColour, Vector2 curMousePos, bool held) {
		if (ctx == nullptr) return;
		auto rect = Vector4(position.x, position.x + size.x, position.y, position.y + size.y);
		if (curMousePos.x < rect.x && curMousePos.x > rect.w && curMousePos.y < rect.z && curMousePos.y > rect.y) {
			if (!held) ctx->fillRectangle(rect, hoverColour, colour.a);
			else ctx->fillRectangle(rect, heldColour, colour.a);
		}
		else ctx->fillRectangle(rect, colour, colour.a);
	};*/

	bool DrawButtonText(Vector2 position, Vector2 size, _RGB colour, _RGB hoverColour, _RGB heldColour, Vector2 curMousePos, bool held, TextHolder text, class BitmapFont* font) {
		return DrawButtonText(position, size, colour, hoverColour, heldColour, curMousePos, held, text, font, 1, Vector2(0, 0));
	};

	bool DrawButtonText(Vector2 position, Vector2 size, _RGB colour, _RGB hoverColour, _RGB heldColour, Vector2 curMousePos, bool held, TextHolder text, class BitmapFont* font, float scale, Vector2 scaleOffset, bool alwaysHold = false) {
		if (ctx == nullptr) return false;
		bool toReturn;
		auto rect = Vector4(position.x, position.x + size.x, position.y, position.y + size.y);
		if (alwaysHold) {
			ctx->fillRectangle(rect, heldColour, colour.a);
			DrawString(Vector2(position.x + scaleOffset.x, position.y * 2 + scaleOffset.y), _RGB(200, 200, 200), text, font, scale);
		}
		if (curMousePos.x < rect.x && curMousePos.x > rect.w && curMousePos.y < rect.z && curMousePos.y > rect.y) {
			if (!held) {
				if (!alwaysHold)
				ctx->fillRectangle(rect, hoverColour, colour.a);
			}
			else {
				if (!alwaysHold)
				ctx->fillRectangle(rect, heldColour, colour.a);
				toReturn = true;
			}
			if (!alwaysHold)
			DrawString(Vector2(position.x + scaleOffset.x, position.y * 2 + scaleOffset.y), _RGB(200, 200, 200), text, font, scale);
		}
		else {
			if (!alwaysHold) {
				ctx->fillRectangle(rect, colour, colour.a);
				DrawString(Vector2(position.x + scaleOffset.x, position.y * 2 + scaleOffset.y), _RGB(255, 255, 255), text, font, scale);
			}
		}
		return toReturn;
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

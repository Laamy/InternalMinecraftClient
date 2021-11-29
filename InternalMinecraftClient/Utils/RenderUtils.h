#pragma once*
#include "../SDK/MinecraftUIRenderContext.h"

class RenderUtils
{
public:
	MinecraftUIRenderContext* ctx;
	GuiData* guiData;
	class BitmapFont* font;
	class Handle* modHandle;
	Vector2 pixelSize = Vector2(1, 1);

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
		if (ctx == nullptr) return false; // tf?
		bool toReturn;
		auto rect = Vector4(position.x, position.x + size.x, position.y, position.y + size.y);
		if (alwaysHold) {
			ctx->fillRectangle(rect, _RGB(115, 115, 115), colour.a);
			DrawString(Vector2(position.x + scaleOffset.x, position.y * 2 + scaleOffset.y), _RGB(100, 100, 100), text, font, scale);
		}
		if (curMousePos.x < rect.x && curMousePos.x > rect.w && curMousePos.y < rect.z && curMousePos.y > rect.y) {
			if (!held) {
				if (!alwaysHold)
					ctx->fillRectangle(rect, _RGB(100, 100, 100), colour.a);
			}
			else {
				if (!alwaysHold)
					ctx->fillRectangle(rect, _RGB(90, 90, 90), colour.a);
				toReturn = true;
			}
			if (!alwaysHold)
				DrawString(Vector2(position.x + scaleOffset.x, position.y * 2 + scaleOffset.y), _RGB(100, 100, 100), text, font, scale);
		}
		else {
			if (!alwaysHold) {
				ctx->fillRectangle(rect, _RGB(15, 15, 15), colour.a);
				DrawString(Vector2(position.x + scaleOffset.x, position.y * 2 + scaleOffset.y), _RGB(255, 255, 255), text, font, scale);
			}
		}
		return toReturn;
	};

	void DrawOutline(Vector2 position, Vector2 size, _RGB colour, float width) {
		if (ctx == nullptr) return;
		ctx->drawRectangle(Vector4(position.x, position.x + size.x, position.y, position.y + size.y), colour, colour.a, (int)width);
	};

	void DrawOutline(Vector2 position, Vector2 size, _RGB colour) {
		if (ctx == nullptr) return;
		ctx->drawRectangle(Vector4(position.x, position.x + size.x, position.y, position.y + size.y), colour, colour.a, (int)(colour.a / 255.0f));
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

	void FillRectAndDrawRect(Vector4 pos, _RGB colour1, _RGB colour2, float opacity, float opacity2, float lineWidth) {
		ctx->fillRectangle(pos, colour1, opacity);
		ctx->drawRectangle(pos, colour2, opacity2, lineWidth);
	};

	void DrawPixel(Vector2 position, _RGB colour) {
		Draw(position, pixelSize, colour);
	};

	void DrawLine(Vector2 firstPoint, Vector2 secondPoint, _RGB colour) {
		float x = secondPoint.x - firstPoint.x;
		float y = secondPoint.y - firstPoint.y;

		float max = std::fmaxf(std::fabs(x), std::fabs(y));

		x /= max;
		y /= max;

		for (int i = 0; i < max; ++i) { // v
			Vector2 calcPixel = Vector2(firstPoint.x, firstPoint.y);
			DrawPixel(calcPixel, colour);

			firstPoint.x += x;
			firstPoint.y += y;
		}
	};

	void SetPixelBounds(Vector2 size) {
		pixelSize = size;
	};

	void DrawTriangleOutline(Vector2 position, Vector2 size, _RGB colour) {
		Vector2 secondPoint = Vector2();
		secondPoint.x = position.x + size.x;
		secondPoint.y = position.y + size.y;

		Vector2 middlePoint = Vector2();
		middlePoint.x = position.x + (size.x / 2);
		middlePoint.y = position.y + (size.y / 2);

		DrawLine(middlePoint, secondPoint, colour);
		DrawLine(middlePoint, Vector2(position.x, secondPoint.y), colour);
		DrawLine(secondPoint, Vector2(position.x, secondPoint.y), colour);
	};

	void DrawTriangle(Vector2 position, Vector2 size, _RGB colour) { // insanely ineffective laggy code
		Vector2 secondPoint = Vector2();
		secondPoint.x = position.x + size.x;
		secondPoint.y = position.y + size.y;

		// I'll use the point max math halved with DrawTriangleOutline for this
		float x = secondPoint.x - position.x;
		float y = secondPoint.y - position.y;

		float max = std::fmaxf(std::fabs(x), std::fabs(y));

		x /= max;
		y /= max;

		for (int i = 0; i < max / 2; ++i) { // v
			Vector2 calcPixel = Vector2(position.x, position.y);
			Vector2 calcSize = Vector2(size.x - (2 * i), size.y - (2 * i));
			DrawTriangleOutline(calcPixel, calcSize, colour);

			position.x += x;
			position.y += y;
		}
	};
};
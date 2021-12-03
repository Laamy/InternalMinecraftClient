#pragma once*
#include "../SDK/MinecraftUIRenderContext.h"
#include "../Utils/VisualElement.h"

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
		ctx->fillRectangle(Rect(position.x, position.x + size.x, position.y, position.y + size.y), colour, colour.a);
	};

	void Draw(Rect rectangle, _RGB colour) {
		if (ctx == nullptr) return;
		ctx->fillRectangle(Rect(rectangle.x, rectangle.z, rectangle.y, rectangle.w), colour, colour.a);
	};

	/*void DrawButton(Vector2 position, Vector2 size, _RGB colour, _RGB hoverColour, _RGB heldColour, Vector2 curMousePos, bool held) {
		if (ctx == nullptr) return;
		auto rect = Rect(position.x, position.x + size.x, position.y, position.y + size.y);
		if (curMousePos.x < rect.x && curMousePos.x > rect.w && curMousePos.y < rect.z && curMousePos.y > rect.y) {
			if (!held) ctx->fillRectangle(rect, hoverColour, colour.a);
			else ctx->fillRectangle(rect, heldColour, colour.a);
		}
		else ctx->fillRectangle(rect, colour, colour.a);
	};*/

	bool DrawButtonText(Vector2 position, Vector2 size, _RGB colour, _RGB hoverColour, _RGB heldColour, Vector2 curMousePos, bool held, TextHolder text, class BitmapFont* font) {
		return DrawButtonText(position, size, colour, hoverColour, heldColour, curMousePos, held, text, font, 1, Vector2(0, 0));
	};

	// Returns TRUE if mouse is inside the specified rectangle
	bool isMouseInRect(Rect pos, Vector2 mousePos)
	{
		if (pos.x < mousePos.x && pos.y < mousePos.y && pos.z > mousePos.x && pos.w > mousePos.y)
			return true;
		return false;
	}

	bool DrawButtonText(Vector2 position, Vector2 size, _RGB colour, _RGB hoverColour, _RGB heldColour, Vector2 curMousePos, bool held, TextHolder text, class BitmapFont* font, float scale, Vector2 scaleOffset, bool alwaysHold = false, VisualElement* vElement = nullptr) {
		if (ctx == nullptr) return false;

		// Values
		_RGB color = _RGB(40,40,40,255);
		Rect boxRect = Rect(position.x, position.y, position.x + size.x, position.y + size.y);

		// Get if mouse is in box
		bool returnValue = isMouseInRect(boxRect, curMousePos);

		// Render
		Draw(boxRect, color);

		// Animate
		if (vElement != nullptr)
		{
			vElement->increment(0.00625f, 0.1f, returnValue);
			if (vElement->fade >= 0)
				Draw(boxRect, _RGB(255.f, 255.f, 255.f, vElement->fade * 255.f));
		}

		// Render text
		DrawString(Vector2(boxRect.x, boxRect.y), _RGB(), text, font);

		return returnValue;
	};

	void DrawOutline(Vector2 position, Vector2 size, _RGB colour, float width) {
		if (ctx == nullptr) return;
		ctx->drawRectangle(Rect(position.x, position.x + size.x, position.y, position.y + size.y), colour, colour.a, (int)width);
	};

	void DrawOutline(Vector2 position, Vector2 size, _RGB colour) {
		if (ctx == nullptr) return;
		ctx->drawRectangle(Rect(position.x, position.x + size.x, position.y, position.y + size.y), colour, colour.a, (int)(colour.a / 255.0f));
	};

	void DrawString(Vector2 position, _RGB colour, TextHolder text, class BitmapFont* font) {
		DrawString(position, colour, text, font, 1.f);
	};

	auto World2Screen(Vector3 position, Vector2& out) { // fixed w2s
		auto level = *clientInst->getLevelRender();

		return clientInst->WorldToScreen(
			level.origin,
			position,
			out,
			clientInst->getFov(),
			guiData->scaledResolution
		);
	};

	void DrawString(Vector2 position, _RGB colour, TextHolder text, class BitmapFont* font, float measureCalc) {
		if (ctx == nullptr) return;
		auto calc = Rect(position.x, position.x + 1000, position.y, position.y + 1000);
		CaretMeasureData measureCalc2 = CaretMeasureData();
		ctx->drawText(font, &calc, &text, colour, colour.a, nullptr, &measureCalc, &measureCalc2);
		ctx->flushText(0);
	};

	void FillRectAndDrawRect(Rect pos, _RGB colour1, _RGB colour2, float opacity, float opacity2, float lineWidth) {
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
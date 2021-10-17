#include <cstdint>

struct _RGB {
	union {
		struct { float r, g, b, a; };
		float arr[4]{};
	};
	bool shouldDelete = true;

	_RGB() {
		this->r = 1;
		this->g = 1;
		this->b = 1;
		this->a = 1;
	};

	_RGB(const _RGB& other) {
		this->r = other.r;
		this->g = other.g;
		this->b = other.b;
		this->a = other.a;
		this->shouldDelete = other.shouldDelete;
	}

	_RGB(const float r, const float g, const float b, const float a = 255) {
		this->r = r / 255.0f;
		this->g = g / 255.0f;
		this->b = b / 255.0f;
		this->a = a / 255.0f;
	};

	_RGB(const int r, const int g, const int b, const int a = 255) {
		this->r = r / 255.0f;
		this->g = g / 255.0f;
		this->b = b / 255.0f;
		this->a = a / 255.0f;
	};

	_RGB(const float r, const float g, const float b, const float a, const bool shouldDelete) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
		this->shouldDelete = shouldDelete;
	};
};

class MinecraftUIRenderContext { // yup hasn't changed never will change
public:
    virtual void Constructor(void);
    virtual float getLineLength(class BitmapFont* font, class TextHolder* text, float textSize, bool unknown);
    virtual float getTextAlpha();
    virtual void setTextAlpha(float alpha);
    virtual __int64 drawDebugText(const float* pos, class TextHolder* text, float* color, float alpha, unsigned int textAlignment, const float* textMeasureData, const void* caretMeasureData);
    virtual __int64 drawText(class BitmapFont* font, struct Vec4* position, class TextHolder* text, _RGB colour, float alpha, unsigned int textAlignment, const float* textMeasureData, const uintptr_t* caretMeasureData);
    virtual void flushText(float timeSinceLastFlush);
    virtual __int64 drawImageNOTIMPLEMENTED();
    virtual __int64 drawNinesliceNOTIMPLEMENTED();
    virtual __int64 flushImagesNOTIMPLEMENTED();
    virtual __int64 beginSharedMeshBatchNOTIMPLEMENTED();
    virtual __int64 endSharedMeshBatchNOTIMPLEMENTED();
    virtual void drawRectangle(struct Vec4 position, _RGB colour, float alpha, int lineWidth);
    virtual void fillRectangle(struct Vec4 position, _RGB colour, float alpha);
};
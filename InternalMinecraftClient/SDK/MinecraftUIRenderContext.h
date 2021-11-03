#include <cstdint>
#include "../Utils/Math.h"
#include "TextHolder.h"

// 48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B FA 48 89 54 24 ? 4C 8B

class BitmapFont {};
class TexturePtr {};

class MinecraftUIRenderContext {
private:
    virtual void Constructor(void);
public:
    virtual float getLineLength(BitmapFont* font, TextHolder* text, float textSize, bool unknown);
    virtual float getTextAlpha();
    virtual void setTextAlpha(float alpha);
    virtual __int64 drawDebugText(const float* pos, TextHolder* text, float* color, float alpha, unsigned int textAlignment, const float* textMeasureData, const void* caretMeasureData);
    virtual __int64 drawText(BitmapFont* font, Vector4* position, TextHolder* text, _RGB colour, float alpha, unsigned int textAlignment, const float* textMeasureData, const uintptr_t* caretMeasureData);
    virtual void flushText(float timeSinceLastFlush);
    virtual void drawImage(TexturePtr* const& texture, Vector4 _1, Vector4 _2, Vector4 _3, Vector4 _4);
private:
    // virtual __int64 Function7(); // drawImage
    virtual __int64 Function8(); // drawNineslice
    virtual void flushImages(); // flushImages
    virtual __int64 Function10(); // beginSharedMeshBatch
    virtual void beginSharedMeshBatch(); // endSharedMeshBatch
public:
    virtual void drawRectangle(Vector4 position, _RGB colour, float alpha, int lineWidth);
    virtual void fillRectangle(Vector4 position, _RGB colour, float alpha);
};
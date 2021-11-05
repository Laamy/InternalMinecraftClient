#pragma once

#include <cstdint>
#include "../Utils/Math.h"
#include "TextHolder.h"

// 48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B FA 48 89 54 24 ? 4C 8B

class TexturePtr {};

class MinecraftUIRenderContext {
private:
    virtual auto Constructor() -> void {};
public:
    virtual float getLineLength(class BitmapFont* font, TextHolder* text, float textSize); // , bool unknown
    virtual float getTextAlpha();
    virtual auto setTextAlpha(float alpha) -> void {};
    virtual auto drawDebugText(const float* pos, TextHolder* text, float* color, float alpha, unsigned int textAlignment, const float* textMeasureData, const void* caretMeasureData) -> void {};
    virtual auto drawText(class BitmapFont* font, Vector4* position, TextHolder* text, _RGB colour, float alpha, unsigned int* textAlignment, const float* textMeasureData, const CaretMeasureData* caretMeasureData) -> void {};
    virtual auto flushText(float timeSinceLastFlush) -> void {};
    virtual auto drawImage(TexturePtr* const& texture, Vector4 _1, Vector4 _2, Vector4 _3, Vector4 _4) -> void {};
private:
    virtual auto drawNineslice() -> void {};
public:
    virtual auto flushImages(float timeSinceLastFlush) -> void {}; // flushImages
private:
    virtual auto beginSharedMeshBatch() -> void {}; // beginSharedMeshBatch
    virtual auto endSharedMeshBatch() -> void {};
public:
    virtual auto drawRectangle(Vector4 position, _RGB colour, float alpha, int lineWidth) -> void {};
    virtual auto fillRectangle(Vector4 position, _RGB colour, float alpha) -> void {};
};
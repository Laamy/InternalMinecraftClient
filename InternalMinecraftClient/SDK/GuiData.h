#include "../Utils/Math.h"

class GuiData {
private:
	char pad_0x0000[0x18]; //0x0000
public:
	Vector2 resolution; //0x0018
private:
	char pad_0x0020[0x8]; //0x0020
public:
	Vector2 scaledResolution; //0x0028
private:
	char pad_0x0030[0x8]; //0x0030
public:
	float scale; //0x0034
private:
	char pad_0x004A[0x16]; //0x004A
public:
    short MouseX; //0x0052
	short MouseY; //0x0054
};

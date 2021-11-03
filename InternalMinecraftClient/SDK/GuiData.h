#include "../Utils/Math.h"

class GuiData {
private:
	char pad_0x0000[0x18]; //0x0000
public:
	Vector2 resolution; //0x0018
	Vector2 resolution2; //0x0020
	Vector2 scaledResolution; //0x0028
private:
	char pad_0x0030[0x8]; //0x0030
public:
	float guiScale; //0x0034
private:
	char pad_0x004A[0x16]; //0x004A
public:
    short MouseX; //0x0052
	short MouseY; //0x0054

public:
	Vector2 scaledMousePos() {
		return Vector2((this->MouseX) * this->guiScale, (this->MouseY) * this->guiScale);
	};
};

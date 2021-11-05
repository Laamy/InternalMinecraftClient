#pragma once

#include "../Utils/Math.h"
#include "MinecraftGame.h"

class ClientInstance {
private:
	char pad_0x0000[0xA8]; //0x0000
public:
	MinecraftGame* mcGame; //0x00A8
	class LoopbackSender* loopbackSender; //0x00B0 
private:
	char pad_0x00B8[0x18]; //0x00B8
public:
	class TimerClass* timerClass; //0x00D0 
private:
	char pad_0x00D8[0x60]; //0x00D8
public:
	Actor* localPlayer; //0x0138 
private:
	char pad_0x0140[0x3A8]; //0x0140
public:
	GuiData* guiData; //0x04E8

public: // Custom Voids
	bool isInGame() {
		if (localPlayer != nullptr && localPlayer->CameraRots.x != 0)
			return true;
		return false;
	}
};
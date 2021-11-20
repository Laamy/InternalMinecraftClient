#pragma once

#include "../Utils/Math.h"
#include "MinecraftGame.h"
#include "Player.h"

class TimerClass2 {
public:
	float timer; //0x0000
};

class TimerClass {
private:
	char pad_0x0000[0xD0]; //0x0000
public:
	TimerClass2* timerClass;
};

class LoopbackSender {
public:
	class _SubLoopbackSender { // 0
	public:
		class __SubLoopbackSender { // 8
		private:
			char pad_0x0000[0x8]; //0x0000
		public:
			class ___SubLoopbackSender { // 0
			public:
				char byteList[5]; //0x0000

			public:
				void RetPacketSender() { // 48 89 5C 24 08 - C3 90 90 90 90
					byteList[0] = 0xC3;
					byteList[1] = 0xC3;
					byteList[2] = 0xC3;
					byteList[3] = 0xC3;
					byteList[4] = 0xC3;
				}
				void RestorePacketSender() { // 48 89 5C 24 08 - C3 90 90 90 90
					byteList[0] = 0x48;
					byteList[1] = 0x89;
					byteList[2] = 0x5C;
					byteList[3] = 0x24;
					byteList[4] = 0x08;
				}
			} subClass;
		} subClass;
	} subClass;

public:
	void RetPacketSender() {
		subClass.subClass.subClass.RetPacketSender();
	}
	void RestorePacketSender() {
		subClass.subClass.subClass.RestorePacketSender();
	}
}; // this 100% wont work :(

class ClientInstance {
public:
	//static std::map<uint64_t, bool> ciKeymap;

private:
	char pad_0x0000[0xA8]; //0x0000
public:
	MinecraftGame* mcGame; //0x00A8
	TimerClass* timerClass; //0x00B0
private:
	char pad_0x00B8[0x18]; //0x00B8
public:
	LoopbackSender* loopbackSender; //0x00D0
private:
	char pad_0x00D8[0x60]; //0x00D8
public:
	//Actor* localPlayer; //0x0138
	char pad_0x0138[0x8]; //0x0138
private:
	char pad_0x0140[0x3A8]; //0x0140
public:
	GuiData* guiData; //0x04E8

public:
	//auto getLocalPlayer() {
	//	return reinterpret_cast<class Actor*>((uintptr_t)(this) + 0x138);
	//};

	auto getGuiData() {
		return reinterpret_cast<GuiData*>((uintptr_t)(this) + 0x4E8);
	};

	auto getTimerClass() {
		return reinterpret_cast<class TimerClass*>((uintptr_t)(this) + 0xD0);
	};

	auto getLoopbackSender() {
		return reinterpret_cast<class LoopbackSender*>((uintptr_t)(this) + 0xB0);
	};

	auto getMcGame() {
		return reinterpret_cast<MinecraftGame*>((uintptr_t)(this) + 0xA8);
	};

	auto getEntityList() {

		std::map<uintptr_t, Actor*> cleanMap = std::map<uintptr_t, Actor*>();

		int i = 0;
		for (auto ent : entityList) {
			cleanMap[i] = ent.second;
			i++;
		}

		return cleanMap;
	};

	auto getLocalPlayer() { // Player class is way different from actor structs so dont get this mixed up pearl/intop :p
		for (auto ent : entityList) {
			return reinterpret_cast<Player*>(ent.second);
		}
	};

public: // Custom Voids
	auto isInGame() {
		return guiData->windowData->inWorld;
	};
	/*
	bool isInGame() {
		if (getLocalPlayer() != nullptr && getLocalPlayer()->CameraRots.x != 0)
			return true;
		return false;
	};
	bool getKeyDown(uint64_t keyId) {
		return ciKeymap[keyId];
	};
	void setKeymap(std::map<uint64_t, bool> map) {
		ciKeymap = map;
	}*/
};

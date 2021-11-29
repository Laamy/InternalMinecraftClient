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
private:
	//Actor* localPlayer; //0x0138
	char pad_0x0138[0x8]; //0x0138
private:
	char pad_0x0140[0x3A8]; //0x0140
public:
	GuiData* guiData; //0x04E8

public:
	auto getGuiData() {
		return reinterpret_cast<GuiData*>((uintptr_t)(this) + 0x4E8);
	};

	auto getLevelRender() {
		return reinterpret_cast<LevelRender*>((uintptr_t)(this) + 0xC0);
	};

	auto getFovX() {
		return reinterpret_cast<float*>((uintptr_t)(this) + 0x670);
	};

	auto getFovY() {
		return reinterpret_cast<float*>((uintptr_t)(this) + 0x684);
	};

	auto getMatrix() {
		return reinterpret_cast<GLMatrix*>((uintptr_t)(this) + 0x2F0);
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

	auto getCPlayer() { // local player in client instance crashes so please leave this like this lol?
		Player* plr = nullptr;
		for (auto ent : entityList) {
			plr = reinterpret_cast<Player*>(ent.first);
			break;
		}
		return plr;
	};

	Vector2 WorldToScreen(Vector3 pos, int width, int height) {
		auto matrix = getMatrix()->matrix;

		Vector4 cc; // cc's im so funny
		cc.x = pos.x * matrix[0] + pos.y * matrix[4] + pos.z * matrix[8] + matrix[12];
		cc.y = pos.x * matrix[1] + pos.y * matrix[5] + pos.z * matrix[9] + matrix[13];
		cc.z = pos.x * matrix[2] + pos.y * matrix[6] + pos.z * matrix[10] + matrix[14];
		cc.w = pos.x * matrix[3] + pos.y * matrix[7] + pos.z * matrix[11] + matrix[15];

		Vector3 NDC; // Normalized Device Coordinates (Idfk what that is i have to researhcx wtf poedo!!)
		NDC.x = cc.x / cc.w;
		NDC.y = cc.y / cc.w;

		Vector2 plrSrn;
		plrSrn.x = (width / 2 * NDC.x) + (NDC.x + width / 2);
		plrSrn.y = -(height / 2 * NDC.y) + (NDC.y + height / 2);

		return plrSrn;
	}

	__forceinline float transformx(const Vector3& p) {
		auto matrix = getMatrix()->matrix;
		return p.x * matrix[0] + p.y * matrix[4] + p.z * matrix[8] + matrix[12];
	}

	__forceinline float transformy(const Vector3& p) {
		auto matrix = getMatrix()->matrix;
		return p.x * matrix[1] + p.y * matrix[5] + p.z * matrix[9] + matrix[13];
	}

	__forceinline float transformz(const Vector3& p) {
		auto matrix = getMatrix()->matrix;
		return p.x * matrix[2] + p.y * matrix[6] + p.z * matrix[10] + matrix[14];
	}

	inline bool WorldToScreen(Vector3 origin, Vector3 pos, Vector2& screen, Vector2 fov, Vector2 displaySize) {
		pos.x -= origin.x;
		pos.y -= origin.y;
		pos.z -= origin.z;

		float x = transformx(pos);
		float y = transformy(pos);
		float z = transformz(pos);

		if (z > 0) return false;

		float mX = (float)displaySize.x / 2.0F;
		float mY = (float)displaySize.y / 2.0F;

		screen.x = mX + (mX * x / -z * fov.x);
		screen.y = mY - (mY * y / -z * fov.y);

		return true;
	}

public: // Custom Voids
	auto isInGame() {
		return guiData->windowData->inWorld;
	};
};

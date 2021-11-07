#pragma once

#include "../Utils/Math.h"
#include "../SDK/Dimension.h"
#include "../SDK/Level.h"
#include "GameMode.h"

class BlockSource {};

class Actor {
private: // Variables
	char pad_0x0000[0x138]; //0x0000
public:
	Vector2 CameraRots; //0x0138
	Vector2 CameraRots2; //0x0140
private:
	char pad_0x0148[0x10]; //0x0148
public:
	Vector3 EyeHeight; //0x0158
private:
	char pad_0x0164[0x70]; //0x0164
public: // 0x1BC
	float fallDistance; //0x01D4
	unsigned char onGround; //0x01D8
	unsigned char onGround2; //0x01D9
	unsigned char WalkingIntoBlock;
	unsigned char onGround3; //0x01DB
	unsigned char WalkingIntoBlock2; //0x01DC
private:
	char pad_0x01DD[0x5B]; //0x01DD
public:
	float StepHeight; //0x0238
private:
	char pad_0x023C[0x4]; //0x023C
public:
	float WalkDistance; //0x0240
	float WalkDistance1; //0x0244
	float MoveDistance; //0x0248
private:
	char pad_0x024C[0xC]; //0x024C
public:
	float MoveDistanceExact; //0x0258
private:
	char pad_0x025C[0x1]; //0x025C
public:
	unsigned char IsInWater; //0x025D
private:
	char pad_0x025E[0x4A]; //0x025E
public:
	__int32 TicksPast; //0x02A8
private:
	char pad_0x02AC[0x1D]; //0x02AC
public:
	unsigned char IsInLava; //0x02C9
private:
	char pad_0x02CA[0x7A]; //0x02CA
public:
	float SpeedCalc; //0x0344
	__int32 SpeedCalc2; //0x0348
	float MoveTick; //0x034C
private:
	char pad_0x0350[0x10]; //0x0350
public:
	BlockSource* blockSource; //0x0360
	Dimension* dimension; //0x0368
	Level* level; //0x0370
private:
	char pad_0x0378[0x88]; //0x0378
public:
	char EntityType[64]; //0xAE3E8838
private:
	char pad_0x0440[0x80]; //0x0440
public:
	AABB Position; //0x04C0
	Vector2 Hitbox; //0x04D8
	AABB Camera; //0x04E0
	Vector3 Velocity; //0x04F8
	Vector3 Velocity2; //0x0504
private:
	char pad_0x0510[0x3C0]; //0x0510
public:
	__int64 IsAfk; //0x08D0
private:
	char pad_0x08D8[0x8]; //0x08D8
public:
	std::string Username; //0xCE89EF28
private:
	char pad_0x0900[0x80]; //0x0900
public:
	unsigned char IsFlying; //0x0980 
private:
	char pad_0x0981[0xB]; //0x0981
public:
	unsigned char CanFly; //0x098C 
private:
	char pad_0x098D[0x23F]; //0x098D
public: // 1.17.34 im unsure how to find nor where gamemode is rn sorry lol
	GameMode* gameMode; //0x0BCC 
private:
	char pad_0x0BD4[0x484]; //0x0BD4
	float N0000020C; //0x1058 
	char pad_0x105C[0xEC]; //0x105C
public:
	unsigned char InInventory; //0x1148
private:
	char pad_0x1149[0xD23]; //0x1149
public:
	unsigned char Gamemode; //0x1E6C
private:
	char pad_0x1E6D[0x393]; //0x1E6D
public:
	Vector2 NetherPortalAnimation; //0x2200
private:
	char pad_0x2208[0x2C]; //0x2208
public:
	Vector3i Position2; //0x2200
	//__int32 PosX; //0x2234
	//__int32 PosY; //0x2238
	//__int32 PosZ; //0x223C
private:
	char pad_0x2240[0x40]; //0x2240
public:
	float IsMoving; //0x2280
private:
	char pad_0x2284[0x2]; //0x2284
public:
	unsigned char IsInPortal; //0x2286
private:
	char pad_0x2287[0xE3]; //0x2287
public:
	unsigned char HeldItemAmount; //0x236A
private:
	char pad_0x236B[0x6D]; //0x236B
public:
	unsigned char SelectedHotbarID; //0x23D8
private:
	char pad_0x23D9[0x37]; //0x23D9
public:
	Vector2 SetRotations; //0x2410
	Vector2 SetRotations2; //0x2418

	bool* _onGround() {
		return reinterpret_cast<bool*>((uintptr_t)(this) + 0x1D8);
	};

	float* SwingAnimation() {
		return reinterpret_cast<float*>((uintptr_t)(this) + 0x7C8);
	};

	AABB* _position() {
		return reinterpret_cast<AABB*>((uintptr_t)(this) + 0x4C0);
	};

	Vector3* _velocity() {
		return reinterpret_cast<Vector3*>((uintptr_t)(this) + 0x4F8);
	};

public: // Functions
	void SetRenderPosition(Vector3 v) {
		Camera.lower = v;
		Camera.upper = v;
	};

	void SetPos(Vector3 v) {
		this->Position.lower.x = v.x;
		this->Position.lower.y = v.y;
		this->Position.lower.z = v.z;

		this->Position.upper.x = v.x + 0.6f;
		this->Position.upper.y = v.y + 1.8f;
		this->Position.upper.z = v.z + 0.6f;
	};

	void PortalAnimation() {
		this->NetherPortalAnimation = Vector2(1, 1);
	};

	void ClearPortalAnimation() {
		this->NetherPortalAnimation = Vector2(0, 0);
	};

	void SetFieldOfView(float v) {
		//*(float*)((uintptr_t)(this) + 0x10F0) = v;
		*(float*)((uintptr_t)(this) + 0x1058) = v;
		//*(float*)((uintptr_t)(this) + 0x1140) = v;
	};

	float FieldOfView() {
		return *reinterpret_cast<float*>(this + 0x1058);
	};

	void FixReadExcp() { // VirtualUnlock
		VirtualUnlock(this, 0x2418);
	};

	Vector2* bodyRots() {
		return reinterpret_cast<Vector2*>((uintptr_t)(this) + 0x138);
	};
};
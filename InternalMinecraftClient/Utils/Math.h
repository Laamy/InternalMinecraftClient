#pragma once
#include <Windows.h>
#include <cmath>

class Math {
public:
	//
};

struct Vector2 {
	union {
		struct {
			float x, y;
		};
		float arr[2];
	};

	Vector2(float x = 0, float y = 0) {
		this->x = x; this->y = y;
	};

	bool operator == (Vector2 v) { return v.x == x && v.y == y; };
	bool operator != (Vector2 v) { return v.x != x || v.y != y; };
};

struct Vector3 {
	union {
		struct {
			float x, y, z;
		};
		float arr[3];
	};

	Vector3(float x = 0, float y = 0, float z = 0) {
		this->x = x; this->y = y; this->z = z;
	};

	Vector3(float f) {
		this->x = x; this->y = f; this->z = f;
	}

	bool operator == (Vector3 v) { return v.x == x && v.y == y && v.z == z; };
	bool operator != (Vector3 v) { return v.x != x || v.y != y || v.z != z; };

	float Distance(Vector3 v) {
		float dX = x - v.x;
		float dY = y - v.y;
		float dZ = z - v.z;
		return std::sqrt(dX * dX + dY * dY + dZ * dZ);
	}
};

struct AABB {
	Vector3 lower;
	Vector3 upper;
};
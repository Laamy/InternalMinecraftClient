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

	bool operator == (Vector3 v) { return v.x == x && v.y == y && v.z == z; };
	bool operator != (Vector3 v) { return v.x != x || v.y != y || v.z != z; };

	float Distance(Vector3 v) {
		float dX = x - v.x;
		float dY = y - v.y;
		float dZ = z - v.z;
		return std::sqrt(dX * dX + dY * dY + dZ * dZ);
	}
};

struct Vector4 {
	union {
		struct {
			float w, x, y, z;
		};
		float arr[3];
	};

	Vector4(float w = 0, float x = 0, float y = 0, float z = 0) {
		this->w = w;
		this->x = x;
		this->y = y;
		this->z = z;
	};

	bool operator == (Vector4 v) { return v.w == w && v.x == x && v.y == y && v.z == z; };
	bool operator != (Vector4 v) { return v.w != w || v.x != x || v.y != y || v.z != z; };

	float Distance(Vector4 v) {
		float dX = x - v.x;
		float dY = y - v.y;
		float dZ = z - v.z;
		return std::sqrt(dX * dX + dY * dY + dZ * dZ);
	}
};


struct Vector3i {
	union {
		struct {
			int x, y, z;
		};
		int arr[3];
	};

	Vector3i(int x = 0, int y = 0, int z = 0) {
		this->x = x; this->y = y; this->z = z;
	};

	bool operator == (Vector3i v) { return v.x == x && v.y == y && v.z == z; };
	bool operator != (Vector3i v) { return v.x != x || v.y != y || v.z != z; };
};

struct AABB {
	Vector3 lower;
	Vector3 upper;
};

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

struct CaretMeasureData {
	int a;
	bool b;

	CaretMeasureData() {
		CaretMeasureData(0xFFFFFFFF, true);
	};
	CaretMeasureData(int param_1, bool param_2) {
		this->a = param_1;
		this->b = param_2;
	};
};
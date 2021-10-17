#include "../Utils/Math.h"
#include "../SDK/Dimension.h"
#include "../SDK/Level.h"

class Actor {
public:
    void InitOffsets(std::map<uint64_t, uint64_t> map) {
        addrMap = map;
    }

    std::map<uint64_t, uint64_t> addrMap;
private: // Large chunks of offsets to shorten updating
    uintptr_t onground() {
        return 0x1D8;
    };
    uintptr_t dimension() {
        return 0x368;
    };
    uintptr_t position() {
        return 0x4C0;
    };
public: // Functions
    void teleport(Vector3 v) {
        Position()->lower.x = v.x;
        Position()->lower.y = v.y;
        Position()->lower.z = v.z;

        Position()->upper.x = v.x + 0.6f;
        Position()->upper.y = v.y + 1.8f;
        Position()->upper.z = v.z + 0.6f;
    };

    void setFieldOfView(float v) { // this sig doesnt work rn
        static unsigned int offset = 0x1140;
        offset = *reinterpret_cast<int*>(addrMap[0]);
        *(float*)((uintptr_t)(this) + offset) = v;
    }
public: // Vars
    Vector2* BodyRots() {
        return reinterpret_cast<Vector2*>((uintptr_t)(this) + 0x138);
    };

    byte* OnGround() {
        return reinterpret_cast<byte*>((uintptr_t)(this) + onground());
    };

    byte* OnGround2() {
        return reinterpret_cast<byte*>((uintptr_t)(this) + onground() + sizeof(byte));
    };

    byte* WalkingIntoBlock() {
        return reinterpret_cast<byte*>((uintptr_t)(this) + onground() + sizeof(byte) + sizeof(byte));
    };

    float* StepHeight() {
        return reinterpret_cast<float*>((uintptr_t)(this) + 0x238);
    };

    bool* IsInWater() {
        return reinterpret_cast<bool*>((uintptr_t)(this) + 0x25D);
    };

    bool* IsInLava() {
        return reinterpret_cast<bool*>((uintptr_t)(this) + 0x2C9);
    };

    Dimension* GetDimension() {
        return reinterpret_cast<Dimension*>((uintptr_t)(this) + dimension());
    };

    Level* GetMultiLevelPtr() {
        return reinterpret_cast<Level*>((uintptr_t)(this) + dimension() + sizeof(uintptr_t));
    };

    AABB* Position() {
        return reinterpret_cast<AABB*>((uintptr_t)(this) + position());
    };

    Vector2* Hitbox() {
        return reinterpret_cast<Vector2*>((uintptr_t)(this) + position() + sizeof(AABB));
    };

    AABB* RenderPosition() {
        return reinterpret_cast<AABB*>((uintptr_t)(this) + position() + sizeof(AABB) + sizeof(Vector2));
    };

    Vector3* Velocity() {
        return reinterpret_cast<Vector3*>((uintptr_t)(this) + position() + sizeof(AABB) + sizeof(Vector2) + sizeof(AABB));
    };
};
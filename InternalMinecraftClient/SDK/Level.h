class Level {
public: // Vars
    std::string* WorldName() {
        return reinterpret_cast<std::string*>((uintptr_t)(this) + 0x518);
    };

    int* TicksPast() {
        return reinterpret_cast<int*>((uintptr_t)(this) + 0x5F0);
    };

    Vector3* EyeHeight() {
        return reinterpret_cast<Vector3*>((uintptr_t)(this) + 0x9F0);
    };

    Vector3* LookingVector() {
        return reinterpret_cast<Vector3*>((uintptr_t*)(this) + 0x9FC);
    };

    byte* SelectedSide() {
        return reinterpret_cast<byte*>((uintptr_t*)(this) + 0xA0C);
    };

    Vector3* LookingPosition() {
        return reinterpret_cast<Vector3*>((uintptr_t*)(this) + 0xA1C);
    };

    byte* LookingAtBlock() { // this is prolly 4 bytes long but oh well
        return reinterpret_cast<byte*>((uintptr_t*)(this) + 0xA78);
    };
};
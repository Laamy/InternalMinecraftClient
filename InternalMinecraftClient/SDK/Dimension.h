class Dimension {
public: // Vars
    std::string* DimensionName() {
        return reinterpret_cast<std::string*>((uintptr_t)(this) + 0x18);
    };
private:
    std::string* DimensionNameLog() {
        return reinterpret_cast<std::string*>((uintptr_t)(this) + 0xB8);
    };
};
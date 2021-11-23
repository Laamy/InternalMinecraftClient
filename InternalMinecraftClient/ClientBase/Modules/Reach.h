#pragma once

class Reach : public Module {
public:
	VirtualFuncHook* func;
	Reach(std::string cat) : Module(cat, "Reach", 0x07) {}

    float reachValue = 7;
    float originalReach = 0;
    float* reachPtr = nullptr;
    unsigned long oldProtect = 0;

    void OnGameTick(Actor* lp) {
        if (reachPtr != 0) {
            *reachPtr = reachValue;
        }
    }

	void OnEnable(ClientInstance* a1, Actor* a2) override {
        static uintptr_t sigOffset = 0x0;
        if (sigOffset == 0x0) {

            sigOffset = Mem::findSig("F3 0F 10 05 ?? ?? ?? ?? 41 0F 28 D9");

            if (sigOffset != 0x0) {
                int offset = *reinterpret_cast<int*>((sigOffset + 4));  // Get Offset from code
                reachPtr = reinterpret_cast<float*>(sigOffset + offset + 8);
                originalReach = *reachPtr;
            }
        }
        if (!VirtualProtect(reachPtr, sizeof(float), PAGE_EXECUTE_READWRITE, &oldProtect)) {
#ifdef _DEBUG
            _logF("couldnt unprotect memory send help");
            __debugbreak();
#endif
        }
    }

	void OnDisable(ClientInstance* a1, Actor* a2) override {
        *reachPtr = originalReach;
        if (reachPtr != 0)
            VirtualProtect(reachPtr, sizeof(float), oldProtect, &oldProtect);
	}
};
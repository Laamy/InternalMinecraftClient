#pragma once

class FloppySwing : public Module {
public:
	FloppySwing(std::string cat) : Module(cat, "FloppySwing", "Combo of FluxSwing, and NoObstuctSwing to make a wiggle animation", 0x07) {}
	void* targetAddress2;
	void* targetAddress;

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		if (targetAddress == nullptr) {
			targetAddress2 = (void*)Mem::findSig("0F 84 ? ? ? ? 48 8B 46 40 48 85 C0");
			targetAddress = (void*)Mem::findSig("F3 ? ? F0 ? ? C8 F3 ? ? C8");
		}
		BYTE* patch2 = (BYTE*)"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress2), patch2, 6);
		BYTE* patch = (BYTE*)"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 4);

	}

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		BYTE* patch2 = (BYTE*)"\x0F\x84\x83\x02\x00\x00\x48\x8B\x46\x40\x48\x85\xC0";
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress2), patch2, 6);
		BYTE* patch = (BYTE*)"\xF3\x0F\x51\xF0\x0F\x28\xC8\xF3\x0F\x59\xC8";//F3 0F 51 F0 0F 28 C8 F3 0F 59 C8
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 4);
	}
};
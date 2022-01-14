#pragma once

class FluxSwing : public Module {
public:
	FluxSwing(std::string cat) : Module(cat, "FluxSwing", "Makes your swing animation looks like flux (a java client)", 0x07) {}
	void* targetAddress;
	void* targetAddress2;
	void OnEnable(ClientInstance* a1, Actor* a2) override {
		if (targetAddress == nullptr)
			targetAddress = (void*)Mem::findSig("0F 84 ? ? ? ? 48 8B 46 40 48 85 C0");
		BYTE* patch = (BYTE*)"\x90\x90\x90\x90\x90\x90";
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 6);
		if (targetAddress2 == nullptr)
			targetAddress2 = (void*)Mem::findSig("48 85 C0 74 ? 48 8B 08 48 85 C9 74 ? 0F B6 49");
		BYTE* patch2 = (BYTE*)"\x90\x90\x90";
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress2), patch2, 3);
	}

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		BYTE* patch = (BYTE*)"\x0F\x84\x83\x02\x00\x00";
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 6);
		BYTE* patch2 = (BYTE*)"\x48\x85\xC0";
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress2), patch2, 3);
	}
};
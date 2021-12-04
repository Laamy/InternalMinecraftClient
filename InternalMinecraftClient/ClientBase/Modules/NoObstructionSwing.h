#pragma once

class NoObstructionSwing : public Module {
public:
	NoObstructionSwing(std::string cat) : Module(cat, "NoObstSwing", "A very smooth animation", 0x07) {}
	void* targetAddress;

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		if (targetAddress == nullptr)
			targetAddress = (void*)Mem::findSig("F3 ? ? F0 ? ? C8 F3 ? ? C8");
		BYTE* patch = (BYTE*)"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 4);

	}

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		BYTE* patch = (BYTE*)"\xF3\x0F\x51\xF0\x0F\x28\xC8\xF3\x0F\x59\xC8";//F3 0F 51 F0 0F 28 C8 F3 0F 59 C8
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 4);
	}
};
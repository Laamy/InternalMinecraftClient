#pragma once

class OldSwing : public Module {
public:
	OldSwing(std::string cat) : Module(cat, "OldSwing", "Looks similar to the old swing animation", 0x07) {}
	void* targetAddress;

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		if (targetAddress == nullptr)
			targetAddress = (void*)Mem::findSig("F3 ? ? C1 ? ? C8 48 8D 15");
		BYTE* patch = (BYTE*)"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 4);

	}

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		BYTE* patch = (BYTE*)"\xF3\x0F\x2C\xC1\x0F\xB7\xC8\x48\x8D\x15";//F3 0F 2C C1 0F B7 C8 48 8D 15
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 4);
	}
};
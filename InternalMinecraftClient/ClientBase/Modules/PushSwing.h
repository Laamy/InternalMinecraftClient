#pragma once

class PushSwing : public Module {
public:
	PushSwing(std::string cat) : Module(cat, "PushSwing", "Combo of NoObjSwing, and OldSwing to make a push animation", 0x07) {}
	void* targetAddress;
	void* targetAddress2;

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		if (targetAddress == nullptr) {
			targetAddress = (void*)Mem::findSig("F3 ? ? F0 ? ? C8 F3 ? ? C8");
			targetAddress2 = (void*)Mem::findSig("F3 ? ? C1 ? ? C8 48 8D 15");
		}
		BYTE* patch2 = (BYTE*)"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress2), patch2, 4);
		BYTE* patch = (BYTE*)"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 4);

	}

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		BYTE* patch2 = (BYTE*)"\xF3\x0F\x2C\xC1\x0F\xB7\xC8\x48\x8D\x15";//F3 0F 2C C1 0F B7 C8 48 8D 15
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress2), patch2, 4);
		BYTE* patch = (BYTE*)"\xF3\x0F\x51\xF0\x0F\x28\xC8\xF3\x0F\x59\xC8";//F3 0F 51 F0 0F 28 C8 F3 0F 59 C8
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 4);
	}
};
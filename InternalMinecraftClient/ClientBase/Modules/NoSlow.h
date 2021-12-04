#pragma once

class NoSlow : public Module {
public:
	NoSlow(std::string cat) : Module(cat, "NoSlow", "no more slowing wow", 0x07) {}
	void* targetAddress;
	void* targetAddress2;
	void OnEnable(ClientInstance* a1, Actor* a2) override {
		if (targetAddress == nullptr)
			targetAddress = (void*)Mem::findSig("F3 0F 11 46 0C 41 C7");
		BYTE* patch = (BYTE*)"\x90\x90\x90\x90\x90\x90";
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 5);

		if (targetAddress2 == nullptr)
			targetAddress2 = (void*)Mem::findSig("F3 0F 11 46 0C F3 0F 10 05");
		BYTE* patch2 = (BYTE*)"\x90\x90\x90\x90\x90\x90";
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress2), patch2, 5);
	}

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		BYTE* patch = (BYTE*)"\xF3\x0F\x11\x46\x0C\x41\xC7";
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 5);
		BYTE* patch2 = (BYTE*)"\xF3\x0F\x11\x46\x0C\xF3\x0F\x10\x05";
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress2), patch2, 5);
	}
};
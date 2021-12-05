#pragma once

class Criticals : public Module {
public:
	Criticals(std::string cat) : Module(cat, "Criticals", "Hit all criticals", 0x00) {}
	void* targetAddress;
	void OnEnable(ClientInstance* a1, Actor* a2) override {
		if (targetAddress == nullptr)
			targetAddress = (void*)Mem::findSig("73 5A 80 B9 D8 01 ? ? ? 75 51");
		BYTE* patch = (BYTE*)"\x90\x90\x90\x90\x90\x90\x90\x90\x90";
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 9);
	}

	void OnGameTick(Actor* a2) {
		/*a2->fallDistance = 0.9f;
		if (a2->onGround)
			a2->Velocity.y = 0.05f;*/
	}

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		BYTE* patch = (BYTE*)"\x73\x5A\x80\xB9\xD8\x01\x00\x00\x00";
		Mem::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 9);
	}
};
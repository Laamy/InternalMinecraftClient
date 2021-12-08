#pragma once

class ElytraSpoof : public Module {
public:
	VirtualFuncHook* func;
	ElytraSpoof(std::string cat) : Module(cat, "ElytraSpoof", "Spoof the game to think you're in elytra flight when moving", 0x07) {
		uintptr_t address = Mem::findSig("48 89 5C ? ? 57 48 81 EC ? ? ? ? 33 FF 89");
		func = hooks->createHook("elytraFlightSpoof", address, timeOfDay);
	}

    void OnEnable(ClientInstance* a1, Actor* a2) override {
        func->enableHook();
    }

    void OnDisable(ClientInstance* a1, Actor* a2) override {
        func->disableHook();
    }

    static float timeOfDay(void* a1, void* a2) {
        return 0;
    }
};
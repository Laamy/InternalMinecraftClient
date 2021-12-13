#pragma once

class ElytraSpoof : public Module {
public:
	VirtualFuncHook* func;
	ElytraSpoof(std::string cat) : Module(cat, "ElytraSpoof", "Spoof the game to think you're wearing elytra", 0x07) {
		uintptr_t address = Mem::findSig("48 89 5C 24 10 57 48 81 EC B0 ?? ?? ?? 33 FF 89");
		func = hooks->createHook("elytraFlightSpoof", address, isUsingElytra);
	}

    void OnEnable(ClientInstance* a1, Actor* a2) override {
        func->enableHook();
    }

    void OnDisable(ClientInstance* a1, Actor* a2) override {
        func->disableHook();
    }

    static float isUsingElytra(void* a1, void* a2) {
        return 0;
    }
};
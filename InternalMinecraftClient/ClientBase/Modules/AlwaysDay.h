#pragma once

class AlwaysDay : public Module {
public:
    VirtualFuncHook* func;
	AlwaysDay(std::string cat) : Module(cat, "AlwaysDay", "Make it constantly day", 0x07) {
        uintptr_t address = Mem::findSig("44 8B C2 B8 ? ? ? ? F7 EA");
        func = hooks->createHook("timeOfDay", address, timeOfDay);
    
    }

    void OnEnable(ClientInstance* a1, Actor* a2) override {
        func->enableHook();
    }

    void OnDisable(ClientInstance* a1, Actor* a2) override {
        func->disableHook();
    }

    static float timeOfDay(__int64 a1, int a2, float a3) {
                return 0;
    }
};

#pragma once

class BlockReach : public Module {
public:
    VirtualFuncHook* func;
    BlockReach(std::string cat) : Module(cat, "BlockReach", "Lets you reach for blocks furthur away", 0x07) {
        uintptr_t address = Mem::findSig("48 83 EC 28 45 84 C0 74 1E");
        func = hooks->createHook("getPickRange", address, getPickRange);

    }

    void OnEnable(ClientInstance* a1, Actor* a2) override {
        func->enableHook();
    }

    void OnDisable(ClientInstance* a1, Actor* a2) override {
        func->disableHook();
    }

    static float getPickRange(GameMode _this, __int64 a2, char a3) {
        return 1000.f;
    }
};
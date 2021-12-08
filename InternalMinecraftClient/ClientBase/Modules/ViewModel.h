#pragma once

class ViewModel : public Module {
public:
    ViewModel(std::string cat) : Module(cat, "ViewModel", "cool viewmodel, also make u not take fall damage", 0x07) {}
    void* targetAddress;

    void OnEnable(ClientInstance* a1, Actor* a2) override {
        if (targetAddress == nullptr)
            targetAddress = (void*)Mem::findSig("00 00 40 40 DB 0F");
        BYTE* patch = (BYTE*)"\x00\x00\x7A\x44";//00 00 E0 40 DB 0F
        Mem::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 4);
    }

    void OnDisable(ClientInstance* a1, Actor* a2) override {
        BYTE* patch = (BYTE*)"\x00\x00\x40\x40\xDB\x0F";//00 00 40 40 DB 0F
        Mem::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 4);
    }
};
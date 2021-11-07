#pragma once

class Module {
public:
    Module(std::string category, std::string name, uintptr_t keybind, bool enabled = false) { // Constructor
        this->category = category;
        this->name = name;
        this->keybind = keybind;
        this->enabled = enabled;
    };

public:
    std::string category;
    std::string name;
    uintptr_t keybind;
    bool enabled;

public: // functions
    virtual void OnEnable(ClientInstance* ci, Actor* lp) {};
    virtual void OnDisable(ClientInstance* ci, Actor* lp) {};

    virtual void OnFrameRender(RenderUtils* ctx) {};
    virtual void OnTick(ClientInstance* ci) {};
    virtual void OnGameTick(Actor* lp) {};

    //virtual void OnKeyDown(uintptr_t keyAddr, bool* cancel) {};
    //virtual void OnKeyUp(uintptr_t keyAddr, bool* cancel) {};
    //virtual void OnKeyHeld(uintptr_t keyAddr, bool* cancel) {};

    //virtual auto OnMouseDown(uintptr_t mouseKeyAddr, bool* cancel) -> void {};
    //virtual auto OnMouseUp(uintptr_t mouseKeyAddr, bool* cancel) -> void {};
    //virtual auto OnMouseHeld(uintptr_t mouseKeyAddr, bool* cancel) -> void {};
};
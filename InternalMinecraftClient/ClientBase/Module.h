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
    virtual auto OnEnable(ClientInstance* ci) -> void {};
    virtual auto OnDisable(ClientInstance* ci) -> void {};

    virtual auto OnFrameRender(RenderUtils* ctx, GuiData* guiDat, bool* cancel) -> void {};
    virtual auto OnTick(ClientInstance* ci) -> void {};
    virtual auto OnGameTick(Actor* lp) -> void {};

    virtual auto OnKeyDown(uintptr_t keyAddr, bool* cancel) -> void {};
    virtual auto OnKeyUp(uintptr_t keyAddr, bool* cancel) -> void {};
    virtual auto OnKeyHeld(uintptr_t keyAddr, bool* cancel) -> void {};

    //virtual auto OnMouseDown(uintptr_t mouseKeyAddr, bool* cancel) -> void {};
    //virtual auto OnMouseUp(uintptr_t mouseKeyAddr, bool* cancel) -> void {};
    //virtual auto OnMouseHeld(uintptr_t mouseKeyAddr, bool* cancel) -> void {};
};
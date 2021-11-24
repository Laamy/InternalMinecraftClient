#pragma once

class ChestRay : public Module {
public:
	VirtualFuncHook* func;
	ChestRay(std::string cat) : Module(cat, "EntityRay", "Only renders entities and block entities", 0x07) {
		uintptr_t address = Mem::findSig("48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 4C 89 4C");
		func = hooks->createHook("OnChunkRender", address, onChunkRender);
	};

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		func->enableHook();
	};

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		func->disableHook();
	};

	static void onChunkRender(void* a1, void* a2) { return; };
};
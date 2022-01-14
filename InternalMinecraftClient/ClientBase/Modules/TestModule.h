#pragma once
#include <Windows.h>

class TestModule : public Module {
public:
	VirtualFuncHook* func;
	TestModule(std::string cat) : Module(cat, "TestModule", "TestModule", 0x07) {
		uintptr_t address = Mem::findSig("41 0F 10 08 48 8B C2 0F"); //Currently Fog Color
		func = hooks->createHook("Test", address, Test);
		std::vector<std::string> options;
		options.push_back("Hive");
		addSetting(Setting(this, "TestSetting", "checkbox", options));
		//48 8B 41 ? 48 8B D1 48 85 C0 74 ? 48 8B 08 48 85 C9 74 ? 48 8B 01 48 FF ?? return this to true and it makes every item enchanted, return to false and everything isint enchanted
		//40 53 48 83 EC 20 80 B9 8C 09 00 00 01 48 8B D9 74 4B canUseOperatorBlocks which when setting to true works in singleplayer
		/* GetSleepTimer sigs that actually work!
		0F BF 81 0C 10 00 00 C3 CC CC CC CC CC CC CC CC
		0F BF 81 0E 10 00 00 C3 CC CC CC CC CC CC CC CC
		0x0100C offset for it
		*/
	}

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		auto player = clientInst->getLocalPlayer();
		hooks->debugEcho("", "Test module!");
		func->enableHook();
	}

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		func->disableHook();
	}

	static void Test(Actor* ent, Vector3 pos) {
		pos = Vector3(10, 17, 10);
	}
	virtual void OnFrameRender(RenderUtils* ctx) {
		//ctx->FillRectAndDrawRect(Rect(10, 100, 10, 100), _RGB(0, 0, 255), _RGB(255, 0, 0), 0.25f, 1.f, 1.f);
	}
	virtual void OnTick(ClientInstance* ci) {}
	virtual void OnGameTick(Actor* lp) {
	}
};
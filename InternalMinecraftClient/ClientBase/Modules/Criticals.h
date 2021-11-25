#pragma once

class Criticals : public Module {
public:
	VirtualFuncHook* func;
	Criticals(std::string cat) : Module(cat, "Criticals", "Hit all criticals", 0x07) {
		//uintptr_t address = Mem::findSig("73 5A 80 B9 D8 01 ? ? ? 75 51"); //if u nop this, and the jump right under, it makes only crits.
		//func = hooks->createHook("Criticals", address, Crits);

	}

	void OnEnable(ClientInstance* a1, Actor* a2) override {
		//func->enableHook();
	}
	void OnGameTick(Actor* a2) {
		a2->fallDistance = 0.9;
		if (a2->onGround)
			a2->Velocity.y = 0.05f;
	}

	void OnDisable(ClientInstance* a1, Actor* a2) override {
		//func->disableHook();
	}

	//static bool Crits(Actor* lp) {
	//	return false;
	//}
};

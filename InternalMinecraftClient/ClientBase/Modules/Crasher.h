#pragma once

class Crasher : public Module {
public:
	Crasher(std::string cat) : Module(cat, "Crasher", "Supposed To Crashes Realms, But Crashes You...", 0x07) {};

	void OnGameTick(Actor* lp){
		lp->setPos(Vector3{0.f,90.f,0.f});
	}

};
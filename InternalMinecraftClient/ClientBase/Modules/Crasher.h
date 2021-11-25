#pragma once

class Crasher : public Module {
public:
	Crasher(std::string cat) : Module(cat, "Crasher", "Supposed To Crashes Realms, But Crashes You...", 0x07) {};

	void OnGameTick(Actor* lp){
		lp->SetPos(Vector3{99999999.f,99999999.f,99999999.f});
	}

};
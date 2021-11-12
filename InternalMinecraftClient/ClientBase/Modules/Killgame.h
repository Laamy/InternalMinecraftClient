#pragma once

class Killgame : public Module {
public:
	Killgame(std::string cat) : Module(cat, "Killgame", 0x07) {};

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		FreeLibraryAndExitThread(static_cast<HMODULE>(0), 1);
	}
};
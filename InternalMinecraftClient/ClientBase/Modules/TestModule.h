#pragma once

class TestModule : public Module {
public:
	TestModule(std::string cat) : Module(cat, "TestModule", 0x07) {};

	void OnTick(ClientInstance* ci) override {
		if (!ci->isInGame() && this->enabled) return;

		//_logf(L"[TreroInternal]: ticking\n");
	};
};
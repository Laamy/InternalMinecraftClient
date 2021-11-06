#pragma once

class TestModule : public Module {
public:
	TestModule(std::string cat) : Module(cat, "TestModule", 0x07) {};

	void OnTick(ClientInstance* ci) override {
		//if (!ci->isInGame() && this->enabled) return;

		if (ci->localPlayer->_onGround())
			_logf(L"[TreroInternal]: onGround is true\n");
		else
			_logf(L"[TreroInternal]: onGround is not false\n");
	};
};
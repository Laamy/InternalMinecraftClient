#pragma once

class TestModule : public Command {
public:
	TestModule(std::string name) : Command("test", "Pro test cmd", "") {};

	void Execute(ClientInstance* ci, Actor* lp) override {
	}
};

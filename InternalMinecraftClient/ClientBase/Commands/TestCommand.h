#pragma once

class TestCommand : public Command {
public:
	TestCommand(std::string name) : Command(name, "test cmd") {};

	void Execute(ClientInstance* ci, Actor* lp) override {
	}
};
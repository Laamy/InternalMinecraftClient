#pragma once

class TestCommand : public Command {
public:
	TestCommand(std::string name) : Command(name, "test cmd") {};

	void Execute(std::vector<std::string> args) override {
		hooks->debugEcho("TestEcho", "Test command!");
	}
};
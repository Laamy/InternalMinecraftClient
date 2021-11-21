#pragma once

class EjectCommand : public Command {
public:
	EjectCommand(std::string name) : Command(name, "Eject Command") {};

	void Execute(ClientInstance* ci, Actor* lp) override {
		clientAlive = false;
	}
};

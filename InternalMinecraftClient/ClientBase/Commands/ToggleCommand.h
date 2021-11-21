#pragma once

class ToggleCommand : public Command {
public:
	ToggleCommand(std::string name) : Command(name, "Toggle Command") {};

	void Execute(ClientInstance* ci, Actor* lp) override {
		//The basic layout :/ to lazy to finish
	}
};

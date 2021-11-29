#pragma once

class DieCommand : public Command {
public:
	DieCommand(std::string name) : Command(name, "Kills you (and u cant respawn :D)") {};

	void Execute(std::vector<std::string> args) override {
		auto lp = clientInst->getCPlayer();
		lp->kill();
	}
};
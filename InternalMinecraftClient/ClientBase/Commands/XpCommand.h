#pragma once

class XpCommand : public Command {
public:
	XpCommand(std::string name) : Command(name, "Gives 100 levels!") {};

	void Execute(std::vector<std::string> args) {
		auto lp = clientInst->getCPlayer();

		lp->addLevels(20);
		lp->addExperience(5);

		lp->displayClientMessage("");
	}
};
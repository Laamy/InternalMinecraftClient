#pragma once

class XpCommand : public Command {
public:
	XpCommand(std::string name) : Command(name, "Gives 100 levels!") {};

	void Execute(std::vector<std::string> args) {
		auto lp = clientInst->getLocalPlayer();

		lp->addLevels(100);
		lp->displayClientMessage("Succesfully gave 100 levels!!!!");
	}
};
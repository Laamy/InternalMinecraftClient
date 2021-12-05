#pragma once

class XpCommand : public Command {
public:
	XpCommand(std::string name) : Command(name, "Gives 100 levels!") {};

	void Execute(std::vector<std::string> args) {
		auto lp = clientInst->getLocalPlayer();

		if (!empty(args[1]) && isNumber(args[1])) {
			int amount = std::stoi(args[1]);
			lp->addLevels(amount);
			lp->displayClientMessage("[Trero Internal] Succesfully gave " + std::string (args[1]) + " level(s)!");
		} else {
			lp->addLevels(100);
			lp->displayClientMessage("[Trero Internal] Succesfully gave 100 levels!");
		}
	}
};
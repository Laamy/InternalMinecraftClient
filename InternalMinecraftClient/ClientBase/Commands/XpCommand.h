#pragma once

class XpCommand : public Command {
public:
	XpCommand(std::string name) : Command(name, "Teleport to the top block above you") {};

	void Execute(std::vector<std::string> args) override {
		auto lp = clientInst->getCPlayer();
		lp->addLevels(100);
	}
};
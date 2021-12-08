#pragma once

class DamageCommand : public Command {
public:
	DamageCommand(std::string name) : Command(name, "Hurt's you as much as you want!") {};

	void Execute(std::vector<std::string> args) override {
		if (!empty(args[1])) {
			auto lp = clientInst->getCPlayer();
			int num = std::stoi(args[1]);
			lp->doFireHurt(num);
		}
	}
};
#pragma once

class TpCommand : public Command {
public:
	TpCommand(std::string name) : Command(name, "Tp's you to selected coordinates") {};

	void Execute(std::vector<std::string> args) override {
		if (!empty(args[1])) {
			auto lp = clientInst->getCPlayer();
			Vector3 pos;
			pos.x = std::stof(args[1]);
			pos.y = std::stof(args[2]);
			pos.z = std::stof(args[3]);
			pos.y += 1.f;
			lp->setPos(pos);
		}
	}
};
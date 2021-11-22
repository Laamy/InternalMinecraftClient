#pragma once

class FixHitbox : public Command {
public:
	FixHitbox(std::string name) : Command(name, "FixHitbox") {};

	void Execute(std::vector<std::string> args) override {
		auto lp = clientInst->getCPlayer();
		lp->SetPos(lp->Position.lower);
	}
};
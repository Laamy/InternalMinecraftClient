#pragma once

class FixHitboxCommand : public Command {
public:
	FixHitboxCommand(std::string name) : Command(name, "Reset's your hitbox") {};

	void Execute(std::vector<std::string> args) override {
		auto lp = clientInst->getCPlayer();
		lp->Hitbox.x = 0.6f;
		lp->Hitbox.y = 1.8f;
	}
};
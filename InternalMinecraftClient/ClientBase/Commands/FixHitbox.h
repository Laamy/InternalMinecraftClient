#pragma once

class FixHitbox : public Command {
public:
	FixHitbox(std::string name) : Command(name, "FixHitbox") {};

	void Execute(ClientInstance* ci, Actor* lp) override {
		lp->SetPos(lp->Position.lower);
	}
};
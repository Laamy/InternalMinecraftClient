#pragma once

class TestCommand : public Command {
public:
	TestCommand(std::string name) : Command(name, "test cmd") {};

	void Execute(std::vector<std::string> args) override {
		/*auto player = clientInst->getCPlayer();
		Vector3 pos;
		std::to_string(pos.x);
		std::to_string(pos.y);
		std::to_string(pos.z);
		pos.x = args.at(1);
		pos.y = args.at(2);
		pos.z = args.at(3);

		player->setPos(pos);*/
	}
};
#pragma once

class TestCommand : public Command {
public:
	TestCommand(std::string name) : Command(name, "Pro") {};

	void Execute(ClientInstance* ci, Actor* lp) override {
		void* a1{};
		auto cse = TextHolder("[TreroInternal]: FUCK");
		_chatMsg(a1, &cse);
	}

};

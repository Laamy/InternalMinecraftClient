#pragma once

#include <algorithm>

class CommandHandler {
public:
    std::vector<Command*> commands;

public:

    void InitCommands() {

        //commands.push_back(new TestCommand("test", "Test command", ""));
    }

	auto findCommand(std::string name) -> Command* {
		std::vector<Command*>* allCmds = commands;
		for (auto cmd : *allCmds) {
			if (cmd->CheckName(name)) {
				return cmd;
			}
		}
		return nullptr;
	}
};

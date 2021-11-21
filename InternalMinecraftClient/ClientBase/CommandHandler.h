#pragma once

#include <algorithm>
#include <vector>
#include "Command.h"
#include "Commands/TestCommand.h"

class CommandHandler {
public:
    std::vector<Command*> commands;

public:

    void InitCommands() {
        commands.push_back(new TestCommand("test"));
    }

    Command* findCommand(std::string name){
        std::vector<Command*> allCmds = commands;
        for (auto cmd : allCmds) {
            if (cmd->CheckName(name)) {
                return cmd;
            }
        }
	return nullptr;
    }
};

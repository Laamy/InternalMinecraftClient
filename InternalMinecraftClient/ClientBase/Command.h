#pragma once
#include <string>
#include <vector>

class Command {
public:
	Command(std::string name, std::string description, std::vector<std::string> aliases) { // Constructor
		this->name = name;
		this->description = description;
		this->aliases = aliases;
	};

public:
	std::string name;
	std::string description;
	std::vector<std::string> aliases;


public: // functions
	virtual void Execute(ClientInstance* ci, Actor* lp) {};
	virtual auto CheckName(std::string Name) -> bool {
	    if(name == this->name) {
		return true;
	    }

	    std::vector<std::string> aliases = aliases;
	    for(auto alias : aliases) {
		if(alias == name) {
			return true;
		}
	    }
	return false;
    }
};

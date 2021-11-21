#pragma once

class Command {
public:
	Command(std::string name, std::string description, std::string alias) { // Constructor
		this->name = name;
		this->description = description;
		this->alias = alias;
	};

public:
	std::string name;
	std::string description;
	std::string alias;


public: // functions
	virtual void Execute(ClientInstance* ci, Actor* lp) {};
};

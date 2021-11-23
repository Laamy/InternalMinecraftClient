#pragma once

class Antibot : public Module {
public:
	Antibot(std::string cat) : Module(cat, "Antibot", "Stop modules from targeting bots", 0x07) {};
};
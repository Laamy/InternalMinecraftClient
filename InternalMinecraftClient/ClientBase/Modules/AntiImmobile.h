#pragma once

class AntiImmobile : public Module {
public:
	AntiImmobile(std::string cat) : Module(cat, "AntiImmobile", 0x07) {};
};
#pragma once

class Longjump : public Module {
public:
	Longjump(std::string cat) : Module(cat, "Longjump", "Jump Longer than before", 0x07) {};

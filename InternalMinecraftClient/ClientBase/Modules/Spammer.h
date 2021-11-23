#pragma once

class Spammer : public Module {
public:
    Spammer(std::string cat) : Module(cat, "Spammer", "Spam chat messages when you type in chat", 0x07) {};
};
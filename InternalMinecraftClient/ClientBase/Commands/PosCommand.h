#pragma once

class PosCommand : public Command {
public:
	PosCommand(std::string name) : Command(name, "Tells Ur Pos") {};

	void Execute(std::vector<std::string> args) {
        auto player = clientInst->getLocalPlayer();
        Vector3 d = *player->getPos();
        d.y -= 2.5f;
        d.x -= 1.f;
        std::string txt1 = std::to_string((int)d.x);
        std::string txt2 = std::to_string((int)d.y);
        std::string txt3 = std::to_string((int)d.z);
        player->displayClientMessage("[TreroInternal] " + txt1 + ", " + txt2 + ", " + txt3);
	}
};
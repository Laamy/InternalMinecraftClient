#pragma once

class NameTags : public Module {
public:
	NameTags(std::string cat) : Module(cat, "NameTags", "Display a nametag over every players head even if their not in entity render distance", 0x07, true) {};

	void OnFrameRender(RenderUtils* ctx) override {
		for (auto ent : clientInst->getEntityList()) {
			// to be developed
		}
	}
};
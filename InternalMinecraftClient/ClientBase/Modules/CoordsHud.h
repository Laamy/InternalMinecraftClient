#pragma once

class CoordsHud : public Module {
public:
	CoordsHud(std::string cat) : Module(cat, "CoordsHud", "Display's your coordinates", 'J') {}

	virtual void OnFrameRender(RenderUtils* ctx) {
		auto player = clientInst->getLocalPlayer();
		auto gm = player->getGamemode();
		Vector3 d = *player->getPos();
		Vector3i* rel = (Vector3i*)&(d);
		std::string txt1 = std::to_string((int)d.x);
		std::string txt2 = std::to_string((int)d.y);
		std::string txt3 = std::to_string((int)d.z);
		ctx->DrawString(Vector2(10, 100), _RGB(0, 0, 255), txt1 + ", " + txt2 + ", " + txt3, ctx->font);
	}
};
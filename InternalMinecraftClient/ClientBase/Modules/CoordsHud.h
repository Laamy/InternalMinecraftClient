#pragma once

class CoordsHud : public Module {
public:
	CoordsHud(std::string cat) : Module(cat, "CoordsHud", "Display's your coordinates", 'J') {}

	virtual void OnFrameRender(RenderUtils* ctx) {
        auto player = clientInst->getLocalPlayer();
        if (clientInst->getGuiData()->IsInGame || clientInst->isInGame() || clientInst->getCPlayer() != nullptr || clientInst->getCPlayer()->canOpenContainerScreen() == true || clientInst->mcGame->canUseKeys()) {
            Vector3 d = *player->getPos();
            d.y -= 2.5f;
            d.x -= 1.f;
            std::string txt1 = std::to_string((int)d.x);
            std::string txt2 = std::to_string((int)d.y);
            std::string txt3 = std::to_string((int)d.z);
            Vector2 TxtPos = Vector2(ctx->guiData->scaledResolution.x - ctx->guiData->scaledResolution.x + 20, ctx->guiData->scaledResolution.y - ctx->guiData->scaledResolution.y + 47);
            Vector2 BoxPos = Vector2(ctx->guiData->scaledResolution.x - ctx->guiData->scaledResolution.x + 17, ctx->guiData->scaledResolution.y - ctx->guiData->scaledResolution.y + 51);
            ctx->DrawOutline(BoxPos, 122, _RGB(0, 0, 0, 182), 6);
            ctx->DrawString(TxtPos, _RGB(255, 255, 255), "Position: " + txt1 + ", " + txt2 + ", " + txt3, ctx->font);
        }
	}
};
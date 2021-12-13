#pragma once

class CoordsHud : public Module {
public:
	CoordsHud(std::string cat) : Module(cat, "CoordsHud", "Display's your coordinates (DO NOT TURN ON IF COORDS ARE ALREADY ON TRUST ME BAD THINGS HAPPEN RUN WHILE U STILL CAN!", 'J') {}
    //80 78 04 ? 74 ? B0 ? 48 83 C4 ? C3 32 C0 48 83 C4 ? C3 CC CC CC CC CC CC CC CC CC 48 83 EC
    void* targetAddress;

    void OnEnable(ClientInstance* a1, Actor* a2) override {
        if (targetAddress == nullptr)
            targetAddress = (void*)Mem::findSig("80 78 04 ? 74 ? B0 ? 48 83 C4 ? C3 32 C0 48 83 C4 ? C3 CC CC CC CC CC CC CC CC CC 48 83 EC");//80 78 04 00 74 07 original signature but it gives 2 adresses so we are using a longer one, this can be useful incase the sig breaks.
        BYTE* patch = (BYTE*)"\x90\x90\x90\x90";
        Mem::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 4);

    }

    void OnDisable(ClientInstance* a1, Actor* a2) override {
        BYTE* patch = (BYTE*)"\x80\x78\x04\x00";
        Mem::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 4);
    }

	virtual void OnFrameRender(RenderUtils* ctx) {
      /*  auto player = clientInst->getLocalPlayer();
        if (clientInst->getGuiData()->IsInGame || clientInst->isInGame()) {
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
        }*/
	}
};
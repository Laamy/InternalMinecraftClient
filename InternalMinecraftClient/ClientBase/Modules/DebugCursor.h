#pragma once

class DebugCursor : public Module {
public:
	DebugCursor(std::string cat) : Module(cat, "DebugCursor", "Debugging cursour :point_up:", 0x07) {};

	void OnFrameRender(RenderUtils* ctx) override {
		ctx->Draw(ctx->guiData->scaledMousePos(), Vector2(5, 5), _RGB(33, 33, 33)); // debug cursor
	}
};
#pragma once

class Tracers : public Module {
public:
	Tracers(std::string cat) : Module(cat, "Tracers", "Draw lines from the middle of your screen to an entity", 0x07) {};

	void OnFrameRender(RenderUtils* ctx) override {
		auto w2s = Vector2();

		auto level = *clientInst->getLevelRender();

		clientInst->WorldToScreen(
			level.origin,
			Vector3(0, 0, 0),
			w2s,
			clientInst->getFov(),
			clientInst->guiData->scaledResolution
		);

		renderUtil.Draw(w2s, Vector2(10, 10), _RGB());
	}
};
#pragma once

class DebugMenu : public Module {
public:
	DebugMenu(std::string cat) : Module(cat, "DebugMenu", 0x07) {};

	Level level;

	void OnFrameRender(RenderUtils* ctx) override {
		if (level.WorldName != "") {
			auto worldText = TextHolder("World: " + level.WorldName);
			auto worldTextPos = Vector2(0, 0);
			ctx->DrawString(worldTextPos, _RGB(255, 255, 255), worldText, ctx->font);
		}
		else {
			auto worldText = TextHolder("World: Unknown");
			auto worldTextPos = Vector2(0, 0);
			ctx->DrawString(worldTextPos, _RGB(255, 255, 255), worldText, ctx->font);
		}
		
		auto labText = TextHolder("Looking At Block: " + level.LookingAtBlock);
		auto labTextPos = Vector2(0, 20);
		ctx->DrawString(labTextPos, _RGB(255, 255, 255), labText, ctx->font);

		if (level.SelectedSide) {
			auto ssText = TextHolder("SelectedSide: " + level.SelectedSide);
			auto ssTextPos = Vector2(0, 40);
			ctx->DrawString(ssTextPos, _RGB(255, 255, 255), ssText, ctx->font);
		}
		else {
			auto ssText = TextHolder("SelectedSide: Unknown");
			auto ssTextPos = Vector2(0, 40);
			ctx->DrawString(ssTextPos, _RGB(255, 255, 255), ssText, ctx->font);
		}
	}
};

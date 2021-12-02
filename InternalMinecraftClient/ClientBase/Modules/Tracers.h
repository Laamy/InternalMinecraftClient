#pragma once

class Tracers : public Module {
public:
	Tracers(std::string cat) : Module(cat, "RenderHome", "Render a message where you enabled this module", 0x07) {};
	Vector3 savedPos = Vector3();

	void OnEnable(ClientInstance* ci, Actor* lp) override {
		if (clientInst->getLocalPlayer() == nullptr) return;

		savedPos = ci->getLocalPlayer()->Position.lower;

		savedPos.x += ci->getLocalPlayer()->Hitbox.x / 2; // Center of player
		savedPos.z += ci->getLocalPlayer()->Hitbox.x / 2;

		savedPos.y += 1.6f; // Eye height
	}

	void OnFrameRender(RenderUtils* ctx) override {
		Vector2 renderPos;

		if (clientInst->getLocalPlayer() != nullptr && ctx->World2Screen(savedPos, renderPos))
		{
			renderUtil.Draw(
				renderPos,
				Vector2(10, 10),
				_RGB()
			);
		}

		renderUtil.DrawString(
			Vector2(10, 10),
			_RGB(),
			TextHolder("GLMatrix w:"),
			font
		);
	}
};
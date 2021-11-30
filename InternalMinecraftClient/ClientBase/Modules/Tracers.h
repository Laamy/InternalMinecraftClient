#pragma once

class Tracers : public Module {
public:
	Tracers(std::string cat) : Module(cat, "Tracers", "Draw lines from the middle of your screen to an entity", 0x07) {};

	void OnFrameRender(RenderUtils* ctx) override {
		for (auto ent : clientInst->getEntityList())
		{
			if (ent.second == nullptr) continue;
			if (ent.second != nullptr || (ent.second->CameraRots != Vector2()
				&& ent.second->CameraRots.x >= 361 && ent.second->CameraRots.y >= 361))
			{
				if (ent.second->isLocalPlayer() == false)
				{
					auto entity = ent.second;

					auto distanceFrom = clientInst->getCPlayer()->Position.lower.Distance(entity->Position.lower);

					auto upperw2s = Vector2();

					if (ctx->World2Screen(entity->Position.upper, upperw2s))
					{
						renderUtil.Draw(
							upperw2s,
							Vector2(10, 10),
							_RGB(128, 128, 128, 128)
						);
					}
				}
			}
		}
	}
};
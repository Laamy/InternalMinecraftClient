#pragma once

class Blink : public Module {
public:
	Blink(std::string cat) : Module(cat, "Blink", "Stop sending packets then send them all at once", 0x07) {};
	Vector3 oldPos;
	Actor* actor;
	
	void OnEnable(ClientInstance* ci, Actor* lp) override {
		ci->loopbackSender->RetPacketSender();
		oldPos = Vector3(lp->Position.upper.x, lp->Position.upper.y, lp->Position.upper.z);
		actor = lp;
	}
	
	void OnFrameRender(RenderUtils* ctx) override {
		if (oldPos != NULL) {
			auto upperw2s = Vector2();

			if (ctx->World2Screen(oldPos, upperw2s))
			{
				renderUtil.Draw(upperw2s, Vector2(17, 30), _RGB(128, 128, 128));
			}
		}
	}

	void OnDisable(ClientInstance* ci, Actor* lp) override {
		ci->loopbackSender->RestorePacketSender();
	}
};

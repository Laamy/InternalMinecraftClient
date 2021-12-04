#pragma once

class Bhop : public Module {
public:
	Bhop(std::string cat) : Module(cat, "Bhop", "Jump around when you move like a bunny :3", 0x07) {};
	void OnGameTick(Actor* lp) override {
		auto player = clientInst->getCPlayer();
		float yaw = (float)player->bodyRots()->y;
		if (keymap['W']) {
			Vector3 po = Vector3(cos((yaw + 90) * 0.01745329251f) * 0.44f, player->Velocity.y, sin((yaw + 90) * 0.01745329251f) * 0.44f);
			player->lerpMotion(po);
			if (player->onGround) {
				player->jumpFromGround();
			}
		}
		if (keymap['A']) {
			Vector3 po = Vector3(cos((yaw + 0) * 0.01745329251f) * 0.44f, player->Velocity.y, sin((yaw + 0) * 0.01745329251f) * 0.44f);
			player->lerpMotion(po);
			if (player->onGround) {
				player->jumpFromGround();
			}
		}
		if (keymap['S']) {
			Vector3 po = Vector3(cos((yaw - 90) * 0.01745329251f) * 0.44f, player->Velocity.y, sin((yaw - 90) * 0.01745329251f) * 0.44f);
			player->lerpMotion(po);
			if (player->onGround) {
				player->jumpFromGround();
			}
		}
		if (keymap['D']) {
			Vector3 po = Vector3(cos((yaw + 180) * 0.01745329251f) * 0.44f, player->Velocity.y, sin((yaw + 180) * 0.01745329251f) * 0.44f);
			player->lerpMotion(po);
			if (player->onGround) {
				player->jumpFromGround();
			}
		}
	}
};
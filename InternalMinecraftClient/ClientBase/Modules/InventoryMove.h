#pragma once

class InventoryMove : public Module {
public:
	InventoryMove(std::string cat) : Module(cat, "InventoryMove", "move in inventory u stupid fuick", 0x07) {};
	void OnGameTick(Actor* lp) override {
		if (lp->canOpenContainerScreen())
			return;
		float yaw = (float)lp->bodyRots()->y;
		if (keymap[' '] && lp->onGround) {
			lp->Velocity.y = 0.40f;
		}
		if (keymap['W']) {
			Vector3 po = Vector3(cos((yaw + 90.f) * 0.01745329251f) * 0.44f, lp->Velocity.y, sin((yaw + 90) * 0.01745329251f) * 0.44f);
			lp->lerpMotion(po);
		}
		if (keymap['A']) {
			Vector3 po = Vector3(cos((yaw + 0.f) * 0.01745329251f) * 0.44f, lp->Velocity.y, sin((yaw + 0) * 0.01745329251f) * 0.44f);
			lp->lerpMotion(po);
		}
		if (keymap['S']) {
			Vector3 po = Vector3(cos((yaw - 90.f) * 0.01745329251f) * 0.44f, lp->Velocity.y, sin((yaw - 90) * 0.01745329251f) * 0.44f);
			lp->lerpMotion(po);
		}
		if (keymap['D']) {
			Vector3 po = Vector3(cos((yaw + 180.f) * 0.01745329251f) * 0.44f, lp->Velocity.y, sin((yaw + 180) * 0.01745329251f) * 0.44f);
			lp->lerpMotion(po);
		}
	}
};
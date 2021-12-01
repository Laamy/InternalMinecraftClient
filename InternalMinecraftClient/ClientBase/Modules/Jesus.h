#pragma once

class Jesus : public Module {
public:
    Jesus(std::string cat) : Module(cat, "Jesus", "Walk on water like jesus", 0x07) {};

    void OnGameTick(Actor* lp) override {
        if (lp->IsInWater || lp->isInLava()) {
            lp->Velocity.y = 0.025f;
            lp->onGround = true;
        }
        /*
        if (lp->IsInWater || lp->IsInLava) {
			Vector3 pos(*lp->getPos());
			float ofs = 1.620010f;
			pos.y = floorf(pos.y - ofs) + 0.6f + ofs;
			lp->setPos(pos);
			if (lp->Velocity.y <= 0)
				lp->lerpybutworky(Vector3(lp->Velocity.x, 0.35, lp->Velocity.z));
				lp->fallDistance = 0;
				lp->onGround = true;
				lp->stepHeight = 1.f;
        }
        */
    }
};

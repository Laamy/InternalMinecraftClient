#pragma once

class OGMFlight : public Module {
public:
	OGMFlight(std::string cat) : Module(cat, "OGMFlight", 0x07) {};
    float speedMod = 0.7f;

	void OnTick(ClientInstance* ci) override {
		auto lp = ci->localPlayer;

        auto calcyaw = (lp->CameraRots.y + 90) * (PI / 180);

        lp->Velocity.x = cos(calcyaw) * speedMod;
        lp->Velocity.y = 0.075f * speedMod;
        lp->Velocity.z = sin(calcyaw) * speedMod;
	};
};
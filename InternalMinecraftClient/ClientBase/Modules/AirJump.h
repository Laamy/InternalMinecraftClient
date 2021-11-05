class AirJump : public Module {
public:
	AirJump(std::string cat) : Module(cat, "AirJump", 0x07) {};

	virtual void OnGameTick(Actor* lp) override {
		lp->Velocity.y = 0.25f;
	};
};
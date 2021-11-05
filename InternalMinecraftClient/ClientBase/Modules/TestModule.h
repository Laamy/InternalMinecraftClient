class TestModule : public Module {
public:
	TestModule(std::string cat) : Module(cat, "TestModule", 0x07) {};

	virtual void OnGameTick(Actor* lp) override {
		_logf(L"[TreroInternal]: ticking\n");
	};
};
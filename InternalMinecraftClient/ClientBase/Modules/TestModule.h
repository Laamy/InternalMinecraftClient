#pragma once
#include <Windows.h>

class TestModule : public Module {
public:
	TestModule(std::string cat) : Module(cat, "TestModule", 'K') {}

    virtual void OnEnable(ClientInstance* ci, Actor* lp) {};
    virtual void OnDisable(ClientInstance* ci, Actor* lp) {};
    virtual void OnFrameRender(RenderUtils* ctx) {};
    virtual void OnTick(ClientInstance* ci) {};
    virtual void OnGameTick(Actor* lp) {};
};
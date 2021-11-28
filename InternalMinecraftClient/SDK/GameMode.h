#pragma once

#include "../Utils/Math.h"

class GameMode {
private:
	virtual __int64 destructorGameMode();
	// Duplicate destructor
public:
	virtual __int64 startDestroyBlock(Vector3i const& pos, unsigned char blockSide, bool& isDestroyedOut);
	virtual __int64 destroyBlock(Vector3i*, unsigned char);
	virtual __int64 continueDestroyBlock(Vector3i const&, unsigned char blockSide, bool& isDestroyedOut);
	virtual __int64 stopDestroyBlock(Vector3i const&);
	virtual __int64 startBuildBlock(Vector3i const&, unsigned char);
	virtual __int64 buildBlock(Vector3i*, unsigned char);
	virtual __int64 continueBuildBlock(Vector3i const&, unsigned char);
	virtual __int64 stopBuildBlock(void);
	virtual __int64 tick(void);

private:
	virtual __int64 getPickRange(__int64 const&, bool);
	virtual __int64 useItem(__int64&);
	virtual __int64 useItemOn(__int64&, Vector3i const&, unsigned char, Vector3 const&, __int64 const*);
	virtual __int64 interact(Actor&, Vector3 const&);

public:
	virtual __int64 attack(Actor*);

private:
	virtual __int64 releaseUsingItem(void);

public:
	virtual void setTrialMode(bool);
	virtual bool isInTrialMode(void);

private:
	virtual __int64 registerUpsellScreenCallback(__int64);

public:
	Actor* player;
};
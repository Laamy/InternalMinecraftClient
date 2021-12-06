#pragma once

class GameMode {
public:
	class Actor* actorPtr; //0x0008
	virtual void Destructor();
	virtual void startDestroyBlock(struct BlockPos const& pos, unsigned char blockSide, bool& isDestroyedOut);
	virtual void destroyBlock(struct BlockPos*, unsigned char);
	virtual void continueDestroyBlock(struct BlockPos const&, unsigned char blockSide, bool& isDestroyedOut);
	virtual void stopDestroyBlock(struct BlockPos const&);
	virtual void startBuildBlock(struct BlockPos const&, unsigned char);
	virtual void buildBlock(struct BlockPos*, unsigned char);
	virtual void continueBuildBlock(struct BlockPos const&, unsigned char);
	virtual void stopBuildBlock(void);
	virtual void tick(void);
	virtual float getPickRange();
	virtual void useItem();
	virtual void useItemOn();
	virtual void interact(Actor*, struct Vec3*);
	virtual void attack(Actor*);
	virtual void releaseUsingItem();
	virtual void setTrialMode(bool);
	virtual bool isInTrialMode(void);
};
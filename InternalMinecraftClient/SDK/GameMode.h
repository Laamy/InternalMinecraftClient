#pragma once

class GameMode {
public:
	class Actor* actorPtr; //0x0008
	virtual void Destructor();
	virtual void startDestroyBlock(Vector3 const& pos, unsigned char blockSide, bool& isDestroyedOut);
	virtual void destroyBlock(Vector3 const& pos, unsigned char);
	virtual void continueDestroyBlock(Vector3 const& pos, unsigned char blockSide, bool& isDestroyedOut);
	virtual void stopDestroyBlock(Vector3 const& pos);
	virtual void startBuildBlock(Vector3 const& pos, unsigned char);
	virtual void buildBlock(Vector3* pos, unsigned char);
	virtual void continueBuildBlock(struct iVector3 const&, unsigned char);
	virtual void stopBuildBlock(void);
	virtual void tick(void);
	virtual float getPickRange();
	virtual void useItem();
	virtual void useItemOn();
	virtual void interact(Actor*, Vector3*);
	virtual void attack(Actor*);
	virtual void releaseUsingItem();
	virtual void setTrialMode(bool);
	virtual bool isInTrialMode(void);
};
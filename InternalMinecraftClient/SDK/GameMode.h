#pragma once

class GameMode {
public:
	class Actor* actorPtr; //0x0008
	virtual void Destructor();
	virtual void startDestroyBlock(struct iVector3 const& pos, unsigned char blockSide, bool& isDestroyedOut);
	virtual void destroyBlock(struct iVector3*, unsigned char);
	virtual void continueDestroyBlock(struct iVector3 const&, unsigned char blockSide, bool& isDestroyedOut);
	virtual void stopDestroyBlock(struct iVector3 const&);
	virtual void startBuildBlock(struct iVector3 const&, unsigned char);
	virtual void buildBlock(struct iVector3*, unsigned char);
	virtual void continueBuildBlock(struct iVector3 const&, unsigned char);
	virtual void stopBuildBlock(void);
	virtual void tick(void);
	virtual float getPickRange();
	virtual void useItem();
	virtual void useItemOn();
	virtual void interact(Actor*, struct Vector3*);
	virtual void attack(Actor*);
	virtual void releaseUsingItem();
	virtual void setTrialMode(bool);
	virtual bool isInTrialMode(void);
};
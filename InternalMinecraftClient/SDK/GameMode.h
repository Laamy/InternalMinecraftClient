#include "../Utils/Math.h"

class GameMode {
public: // VTable
	virtual void structGameMode();
	virtual bool startDestroyBlock(Vector3i* pos, char blockFace, bool a3);
	virtual bool destroyBlock(Vector3i* pos, char blockFace);
	virtual bool continueDestroyBlock(Vector3i* pos, char blockFace, Vector3* a3, bool a4);
	virtual void stopDestroyBlock(Vector3i* pos);
	virtual void startBuildBlock(Vector3i* pos, char blockFace);
	virtual bool buildBlock(Vector3i* pos, char blockFace);
	virtual void continueBuildBlock(Vector3i* pos, char blockFace);
	virtual void stopBuildBlock();
	virtual void tick();
	virtual float getPickRange(__int64* inputMode, bool a2);
	virtual bool useItem(__int64* itemStack);
	virtual bool useItemOn(__int64* itemStack, Vector3i* pos, char blockFace, Vector3* a4, __int64* block);
	virtual bool interact(class Actor* actor, Vector3* pos);
	virtual bool attack(class  Actor* actor);
	virtual void releaseUsingItem();
	virtual bool setTrialMode(); // purely for the sake of adding them their now here.
	virtual bool isInTrialMode();
	virtual void registerUpsellScreenCallback();

public: // Variables
	Actor* player;
};
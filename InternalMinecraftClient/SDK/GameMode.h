#include "../Utils/Math.h"

struct GameMode {
public: // VTable
	virtual void destructorGameMode();
	virtual bool startDestroyBlock(Vector3i* pos, char blockFace, bool param_3);
	virtual bool destroyBlock(Vector3i* pos, char blockFace);
	virtual bool continueDestroyBlock(Vector3i* pos, char blockFace, Vector3* param_3, bool param_4);
	virtual void stopDestroyBlock(Vector3i* pos);
	virtual void startBuildBlock(Vector3i* pos, char blockFace);
	virtual bool buildBlock(Vector3i* pos, char blockFacee);
	virtual void continueBuildBlock(Vector3i* pos, char blockFace);
	virtual void stopBuildBlock();
	virtual void tick();
	virtual float getPickRange(__int64* inputMode, bool param_2);
	virtual bool useItem(__int64* itemStack);
	virtual bool useItemOn(__int64* itemStack, Vector3i* pos, char blockFace, Vector3* param_4, __int64* block);
	virtual bool interact(Actor* actor, Vector3* pos);
	virtual bool attack(Actor* actor);
	virtual void releaseUsingItem();
	// Im aware there are 3 functions down here aswell but they seem fucking useless tbh

public: // Variables
	class Actor* player;
};
#include "../Utils/Math.h"

class BlockPos {};
class Block {};
class InputMode {};
class ItemStack {};

struct GameMode {
	class Actor* player;
private:
	virtual void destructorGameMode();
	virtual bool startDestroyBlock(BlockPos* pos, char blockFace, bool param_3);
	virtual bool destroyBlock(BlockPos* pos, char blockFace);
	virtual bool continueDestroyBlock(BlockPos* pos, char blockFace, Vector3* param_3, bool param_4);
	virtual void stopDestroyBlock(BlockPos* pos);
	virtual void startBuildBlock(BlockPos* pos, char blockFace);
	virtual bool buildBlock(BlockPos* pos, char blockFacee);
	virtual void continueBuildBlock(BlockPos* pos, char blockFace);
	virtual void stopBuildBlock();
	virtual void tick();
	virtual float getPickRange(InputMode* inputMode, bool param_2);
	virtual bool useItem(ItemStack* itemStack);
	virtual bool useItemOn(ItemStack* itemStack, BlockPos* pos, char blockFace, Vector3* param_4, Block* block);
	virtual bool interact(Actor* actor, Vector3* pos);
	virtual bool attack(Actor* actor);
	virtual void releaseUsingItem();
};
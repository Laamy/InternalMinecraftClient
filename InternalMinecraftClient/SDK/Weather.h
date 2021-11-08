#pragma once

class Weather {
private:
	virtual void TryroFunc0(); // constructors
	virtual void TryroFunc1();
	virtual void TryroFunc2();
	virtual void TryroFunc3();
	virtual void TryroFunc4(); // constructors
public:
	virtual void onSourceCreated(class BlockSource&);
	virtual void onSourceDestroyed(BlockSource&);
	virtual void onAreaChanged(BlockSource&, class BlockPos const&, class BlockPos const&);
	virtual void onBlockChanged(BlockSource&, class BlockPos const&, class uint, class Block const&, class Block const&, int, class ActorBlockSyncMessage const*, class BlockChangedEventTarget);
	virtual void onBrightnessChanged(BlockSource&, BlockPos const&);
	virtual void onBlockEntityChanged(BlockSource&, class BlockActor&);
	virtual void onBlockEntityAboutToBeRemoved(); //removed
	virtual void onEntityChanged(BlockSource&, class Actor&);
	virtual void onBlockEvent(BlockSource&, int, int, int, int, int);
	virtual void allChanged(void);
	virtual void addParticle(class ParticleType, Vector3 const&, Vector3 const&, int, class CompoundTag const*, bool);
	virtual void sendServerLegacyParticle(class ParticleType, Vector3 const&, Vector3 const&, int);
	virtual void addParticleEffect(class HashedString const&, Vector3 const&, class MolangVariableMap const&);
	virtual void addParticleEffect(class HashedString const&, class Actor const&, HashedString const&, Vector3 const&, MolangVariableMap const&);
	virtual void addTerrainParticleEffect(BlockPos const&, class Block const&, Vector3 const&, float, float, float);
	virtual void addTerrainSlideEffect(BlockPos const&, class Block const&, Vector3 const&, float, float, float);
	virtual void addBreakingItemParticleEffect(Vector3 const&, ParticleType, class TextureUVCoordinateSet const&, bool);
	virtual void playMusic(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, Vector3 const&, float, float);
	virtual void playStreamingMusic(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, int, int, int);
	virtual void onEntityAdded(class Actor&);
	virtual void onEntityRemoved(class Actor&);
	virtual void onChunkLoaded(class ChunkSource&, class LevelChunk&);
	virtual void onSubChunkLoaded(ChunkSource&, class LevelChunk&, short);
	virtual void onChunkUnloaded(LevelChunk&);
	virtual void onLevelDestruction(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void levelEvent(class LevelEvent, Vector3 const&, int);
	virtual void levelEvent(class LevelEvent, CompoundTag const&);
	virtual void levelSoundEvent(class LevelSoundEvent, Vector3 const&, int, class ActorDefinitionIdentifier const&, bool, bool);
	virtual void levelSoundEvent(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, Vector3 const&, float, float);
	virtual void stopSoundEvent(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void stopAllSounds(void);
	virtual void takePicture(); //removed
	virtual void playerListChanged(void);

private:
	char pad_0x0000[0x38]; //0x0000
public:
	bool isRaining; //0x0038
private:
	char pad_0x0039[0xB]; //0x0039
public:
	bool isLightning; //0x0044
private:
	char pad_0x0045[0x3]; //0x0045
public:
	float lightningLevel; //0x0048
};
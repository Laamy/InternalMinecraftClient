#pragma once

#include <string>
#include "Weather.h"
#include "Packet/Packet.h"

class Dimension {
private:
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual void Function13();
	virtual void Function14();
public:
	virtual void allChanged(void);
	virtual void addParticle(class ParticleType, Vector3 const&, Vector3 const&, int, class CompoundTag const*, bool);
	virtual void sendServerLegacyParticle(class ParticleType, Vector3 const&, Vector3 const&, int);
private:
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual void Function21();
	virtual void Function22();
public:
	virtual void playMusic(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, Vector3 const&, float, float);
	virtual void playStreamingMusic(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, int, int, int);
	virtual void onEntityAdded(class Actor&);
	virtual void onEntityRemoved(class Actor&);
private:
	virtual void Function27();
	virtual void Function28();
public:
	virtual void onChunkUnloaded(class LevelChunk&);
	virtual void onLevelDestruction(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void levelEvent(class LevelEvent, Vector3 const&, int);
	virtual void levelEvent(class LevelEvent, class CompoundTag const&);
private:
	virtual void Function33();
public:
	virtual void levelSoundEvent(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, Vector3 const&, float, float);
	virtual void stopSoundEvent(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void stopAllSounds(void);
private:
	virtual void Function37();
public:
	virtual void playerListChanged(void);
	virtual void init(void);
	virtual void tick(void);
	virtual void tickRedstone(void);
private:
	virtual void Function42();
	virtual void Function43();
	virtual void Function44();
public:
	virtual bool isNaturalDimension(void);
	virtual bool isValidSpawn(int, int);
	virtual float getBrightnessDependentFogColor();
	virtual bool isFoggyAt(int, int);
	virtual int getCloudHeight(void);
	virtual int getDefaultBiome(void);
	virtual void mayRespawnViaBed(void);
	virtual void hasGround(void);
	virtual int getSpawnPos(void);
	virtual int getSpawnYPosition(void);
	virtual void hasBedrockFog(void);
	virtual int getClearColorScale(void);
	virtual void showSky(void);
	virtual bool isDay(void);
	virtual float getSunIntensity(float, Vector3 const&, float);
	virtual void forceCheckAllNeighChunkSavedStat(void);
private:
	virtual void Function61();
public:
	virtual void deserialize(class CompoundTag const&);
	virtual void serialize(class CompoundTag&);
	virtual void sendBroadcast(Packet const&, class Player*);
private:
	virtual void Function65();
public:
	virtual bool isActorRelevantForPlayer(class Player&, class Actor const&);
	virtual int getLightTextureImageBuilder(void);
	virtual int getBrightnessRamp(void);
	virtual void startLeaveGame(void);
	virtual float getTimeOfDay(int, float);
	virtual void _createChunkBuildOrderPolicy(void);

private:
	char pad_0x0000[0x18]; //0x0000
public:
	std::string DimenstionName; //0x0034 
private:
	char pad_0x0038[0xD8]; //0x0038
public:
	Weather* weather; //0x0110
};
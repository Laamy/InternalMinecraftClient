#pragma once

class Level {
private:
	virtual void TryreoFunc0();
	virtual void TryreoFunc1();
	virtual void TryreoFunc2();
	virtual void TryreoFunc3();
public:
	virtual void initialize(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, class LevelSettings const&, class LevelData*, class Experiments const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const*);
	virtual void postProcessResources(void);
	virtual void startLeaveGame(void);
	virtual bool isLeaveGameDone(void);
	virtual void createDimension(); //removed
	virtual int getDimension(); //removed
	virtual void forEachDimension(); //removed
	virtual void forEachDimension(class A); //removed
	virtual int getChunkTickRange(void);
	virtual int getPortalForcer(void);
	virtual void requestPlayerChangeDimension(); //removed
	virtual void entityChangeDimension(); //removed
	virtual int getSpawner(void);
	virtual int getProjectileFactory(void);
	virtual int getEntityDefinitions(void);
	virtual int getActorAnimationGroup(void);
	virtual int getActorAnimationControllerGroup(void);
	virtual int getBlockDefinitions(void);
	virtual int getBlockComponentFactory(void);
	virtual int getBlockComponentFactory2(void);
	virtual int getActorPropertyGroup(void);
	virtual int getSpawnRules(void);
	virtual int getSpawnGroupRegistry(void);
	virtual int getSpawnRulesMutable(void);
	virtual int getSpawnSettings(void);
	virtual void setSpawnSettings(class SpawnSettings const&);
	virtual int getBehaviorTreeGroup(void);
	virtual int getBehaviorFactory(void);
	virtual int getDifficulty(void);
	virtual int getInternalComponentRegistry(void);
	virtual int getDimensionConversionData(void);
	virtual int getSpecialMultiplier(); //removed
	virtual void hasCommandsEnabled(void);
	virtual void useMsaGamertagsOnly(void);
	virtual void setMsaGamertagsOnly(bool);
	virtual void registerEntity(); //removed
	virtual void addEntity(); //removed
	virtual void addGlobalEntity(); //removed
	virtual void addAutonomousEntity(); //removed
	virtual void addUser(); //removed
	virtual void addDisplayEntity(); //removed
	virtual void removeDisplayEntity(class WeakEntityRef);
	virtual void suspendPlayer(class Player&);
	virtual void resumePlayer(Player&);
	virtual bool isPlayerSuspended(Player&);
	virtual void removeActorAndTakeEntity(WeakEntityRef);
	virtual void takeEntity(WeakEntityRef, class LevelChunk*);
	virtual void fetchEntity(uint64_t, bool);
	virtual int getRuntimeEntity(class ActorRuntimeID, bool);
	virtual int getMob(uint64_t);
	virtual int getPlayer(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual int getPlayer(); //removed
	virtual int getPlayerByXuid(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual int getPlayerFromUnknownIdentifier(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual int getPlayer(uint64_t);
	virtual int getPlatformPlayer(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual int getPlayerFromServerId(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual int getRuntimePlayer(ActorRuntimeID);
	virtual int getNumRemotePlayers(void);
	virtual int getPrimaryLocalPlayer(void);
	virtual int getRandomPlayer(void);
	virtual int getNewPlayerId(void);
	virtual int getEventing(void);
	virtual int getPlayerColor(Player const&);
	virtual int getCurrentTick(void);
	virtual int getCurrentServerTick(void);
	virtual void removeAllNonPlayerEntities(uint64_t);
	virtual int getBiomeRegistry(void);
	virtual int getBiomeRegistry2(void);
	virtual int getBlockPalette(void);
	virtual int getBlockPalette2(void);
	virtual int getFeatureRegistry(void);
	virtual int getFeatureRegistry2(void);
	virtual int getFeatureTypeFactory(void);
	virtual int getFeatureTypeFactory2(void);
	virtual int getJigsawStructureRegistry(void);
	virtual int getJigsawStructureRegistry2(void);
	virtual int getStructureManager(void);
	virtual int getStructureManager2(void);
	virtual int getBiomeComponentFactory(void);
	virtual int getBiomeComponentFactory2(void);
	virtual int getSurfaceBuilderRegistry(void);
	virtual int getSurfaceBuilderRegistry2(void);
	virtual int getDimensionFactory(void);
	virtual int getDimensionFactory2(void);
	virtual int getLightTextureImageBuilderFactory(void);
	virtual int getLightTextureImageBuilderFactory2(void);
	virtual void addListener(class LevelListener&);
	virtual void removeListener(class LevelListener&);
	virtual void tickEntities(void);
	virtual void tickEntitySystems(void);
	virtual int getPauseManager(void);
	virtual int getPauseManager2(void);
	virtual void onPlayerDeath(Player&, class ActorDamageSource const&);
	virtual void tick(void);
	virtual void directTickEntities(class BlockSource&);
	virtual void animateTick(Actor&);
	virtual void explode(class BlockSource&, Actor*, Vector3 const&, float, bool, bool, float, bool);
	virtual void explode(class Explosion&);
	virtual void spawnParticleEffect(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, Vector3 const&, Dimension*);
	virtual void spawnParticleEffect(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, Actor const&, Vector3 const&);
	virtual void denyEffect(class BlockSource&, Vector3 const&);
	virtual void potionSplash(); //removed
	virtual void applyLiquidPhysicsToActor(Actor*, class MaterialType);
	virtual void extinguishFire(class BlockSource&, class BlockPos const&, class uchar);
	virtual void findPath(Actor&, int, int, int, class NavigationComponent&);
	virtual void findPath(Actor&, Actor&, NavigationComponent&);
	virtual void updateSleepingPlayerList(void);
	virtual int getTime(void);
	virtual void setTime(int);
	virtual int getSeed(void);
	virtual int getSharedSpawnPos(void);
	virtual void setDefaultSpawn(class BlockPos const&);
	virtual int getDefaultSpawn(void);
	virtual void setDefaultGameType(class GameType);
	virtual int getDefaultGameType(void);
	virtual void setDifficulty(class Difficulty);
	virtual void setMultiplayerGameIntent(bool);
	virtual int getMultiplayerGameIntent(void);
	virtual void setMultiplayerGame(bool);
	virtual bool isMultiplayerGame(void);
	virtual void setLANBroadcastIntent(bool);
	virtual int getLANBroadcastIntent(void);
	virtual void setLANBroadcast(bool);
	virtual int getLANBroadcast(void);
	virtual void setXBLBroadcastIntent(); //removed
	virtual int getXBLBroadcastIntent(void);
	virtual void hasXBLBroadcastIntent(void);
	virtual void setXBLBroadcastMode(); //removed
	virtual int getXBLBroadcastMode(void);
	virtual void hasXBLBroadcast(void);
	virtual void setPlatformBroadcastIntent(); //removed
	virtual int getPlatformBroadcastIntent(void);
	virtual void hasPlatformBroadcastIntent(void);
	virtual void setPlatformBroadcastMode(); //removed
	virtual int getPlatformBroadcastMode(void);
	virtual void hasPlatformBroadcast(void);
	virtual void setHasLockedBehaviorPack(bool);
	virtual void setHasLockedResourcePack(bool);
	virtual void setCommandsEnabled(bool);
	virtual void setWorldTemplateOptionsUnlocked(void);
	virtual void hasLevelStorage(void);
	virtual int getLevelStorage(void);
	virtual int getLevelStorage2(void);
	virtual int getLevelData(void);
	virtual int getLevelData2(void);
	virtual int getPhotoStorage(void);
	virtual void createPhotoStorage(void);
	virtual void setEducationLevelSettings(class EducationLevelSettings);
	virtual int getEducationLevelSettings(void);
	virtual void save(void);
	virtual void saveEducationLevelSettings(void);
	virtual void saveLevelData(void);
	virtual void saveGameData(void);
	virtual void saveVillages(void);
	virtual void savePlayers(void);
	virtual void savePlayer(Player&);
	virtual void saveBiomeData(void);
	virtual void saveDirtyChunks(void);
	virtual void saveAdditionalData(void);
	virtual void requestTimedStorageDeferment(void);
	virtual void _checkUserStorage(void);
	virtual int getTickingAreasMgr(void);
	virtual int getTickingArea(); //removed
	virtual void addParticle(class ParticleType, Vector3 const&, Vector3 const&, int, class CompoundTag const*, bool);
	virtual void sendServerLegacyParticle(ParticleType, Vector3 const&, Vector3 const&, int);
	virtual void playSound(class LevelSoundEvent, Vector3 const&, int, class ActorDefinitionIdentifier const&, bool, bool);
	virtual void playSound(LevelSoundEvent, Vector3 const&, float, float);
	virtual void playSound(class BlockSource&, LevelSoundEvent, Vector3 const&, int, ActorDefinitionIdentifier const&, bool, bool);
	virtual void playSynchronizedSound(class BlockSource&, LevelSoundEvent, Vector3 const&, class Block const&, ActorDefinitionIdentifier const&, bool, bool);
	virtual void playSynchronizedSound(class BlockSource&, LevelSoundEvent, Vector3 const&, int, ActorDefinitionIdentifier const&, bool, bool);
	virtual void setRemotePlayerEventCoordinator(); //removed
	virtual int getRemotePlayerEventCoordinator(void);
	virtual void setServerPlayerEventCoordinator(); //removed
	virtual int getServerPlayerEventCoordinator(void);
	virtual void setClientPlayerEventCoordinator(); //removed
	virtual int getClientPlayerEventCoordinator(void);
	virtual void setActorEventCoordinator(); //removed
	virtual int getActorEventCoordinator(void);
	virtual void setBlockEventCoordinator(); //removed
	virtual int getBlockEventCoordinator(void);
	virtual void setItemEventCoordinator(); //removed
	virtual int getItemEventCoordinator(void);
	virtual void setServerNetworkEventCoordinator(); //removed
	virtual int getServerNetworkEventCoordinator(void);
	virtual int getLevelEventCoordinator(void);
	virtual void handleLevelEvent(class LevelEvent, Vector3 const&, int);
	virtual void handleLevelEvent(LevelEvent, CompoundTag const&);
	virtual void handleSoundEvent(LevelSoundEvent, Vector3 const&, int, ActorDefinitionIdentifier const&, bool, bool);
	virtual void handleSoundEvent(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, Vector3 const&, float, float);
	virtual void handleStopSoundEvent(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void handleStopAllSounds(void);
	virtual void broadcastLevelEvent(LevelEvent, Vector3 const&, int, class UserEntityIdentifierComponent const*);
	virtual void broadcastLevelEvent(LevelEvent, CompoundTag const&, UserEntityIdentifierComponent const*);
	virtual void broadcastLocalEvent(class BlockSource&, LevelEvent, Vector3 const&, int);
	virtual void broadcastLocalEvent(class BlockSource&, LevelEvent, Vector3 const&, Block const&);
	virtual void broadcastSoundEvent(class BlockSource&, LevelSoundEvent, Vector3 const&, Block const&, ActorDefinitionIdentifier const&, bool, bool);
	virtual void broadcastSoundEvent(class BlockSource&, LevelSoundEvent, Vector3 const&, int, ActorDefinitionIdentifier const&, bool, bool);
	virtual void broadcastActorEvent(Actor&, class ActorEvent, int);
	virtual void addBossEventListener(class BossEventListener*);
	virtual void removeBossEventListener(BossEventListener*);
	virtual void broadcastBossEvent(class BossEventUpdateType, uint64_t const&, class BossEventPacket const&);
	virtual void broadcastBossEvent(BossEventUpdateType);
	virtual void areBossEventListenersReady(void);
	virtual void addChunkViewTracker(); //removed
	virtual void pruneChunkViewTrackers(void);
	virtual void onChunkReload(class Bounds const&);
private:
	virtual void TryroFunc211();
public:
	virtual int getActivePlayerCount(void);
	virtual int getActiveUsersCount(void);
private:
	virtual void TryroFunc214(); //removed chunk
	virtual void TryroFunc215();
	virtual void TryroFunc216();
	virtual void TryroFunc217();
	virtual void TryroFunc218();
public:
	virtual int getUserCount(void);
	virtual void countUsersWithMatchingNetworkId(class NetworkIdentifier const&);
	virtual int getUsers(void);
	virtual int getUsers2(void);
	virtual int getEntities(void);
	virtual void onSubChunkLoaded(class ChunkSource&, LevelChunk&, short);
	virtual void onChunkLoaded(class ChunkSource&, LevelChunk&);
	virtual void onChunkDiscarded(LevelChunk&);
	virtual void queueEntityDestruction(); //removed
	virtual void removeEntityReferences(Actor&, bool);
	virtual void removeEntity(Actor&);
	virtual void removeEntity(WeakEntityRef);
	virtual void removeEntityIfExists(Actor*);
	virtual void forceRemoveEntity(Actor&);
	virtual void forceFlushRemovedPlayers(void);
	virtual void loadFunctionManager(void);
	virtual void levelCleanupQueueEntityRemoval(); //removed
	virtual void registerTemporaryPointer(class _TickPtr&);
	virtual void unregisterTemporaryPointer(_TickPtr&);
	virtual void destroyBlock(class BlockSource&, BlockPos const&, bool);
	virtual void upgradeStorageVersion(class StorageVersion);
	virtual void suspendAndSave(void);
	virtual void waitAsyncSuspendWork(void);
	virtual void _destroyEffect(class BlockPos const&, Block const&, int);
	virtual void addParticleEffect(class HashedString const&, Vector3 const&, class MolangVariableMap const&);
	virtual void addParticleEffect(HashedString const&, Actor const&, HashedString const&, Vector3 const&, MolangVariableMap const&);
	virtual void addTerrainParticleEffect(class BlockPos const&, Block const&, Vector3 const&, float, float, float);
	virtual void addTerrainSlideEffect(class BlockPos const&, Block const&, Vector3 const&, float, float, float);
	virtual void addBreakingItemParticleEffect(Vector3 const&, ParticleType, class TextureUVCoordinateSet const&, bool);
	virtual int getNewUniqueID(void);
	virtual int getNextRuntimeID(void);
	virtual int getTickingOffsets(void);
	virtual int getClientTickingOffsets(void);
	virtual bool isExporting(void);
	virtual void setIsExporting(bool);
	virtual int getSavedData(void);
	virtual int getMapSavedData(uint64_t);
	virtual int getMapSavedData(CompoundTag const&);
	virtual int getMapSavedData(CompoundTag const*);
	virtual void requestMapInfo(uint64_t, bool);
	virtual void expandMapByID(uint64_t, bool);
	virtual void copyAndLockMap(uint64_t, uint64_t);
private:
	virtual void TryroFunc261();
	virtual void TryroFunc262();
	virtual void TryroFunc263();
	virtual void TryroFunc264();
public:
	virtual void setLevelId(std::basic_string<char, std::char_traits<char>, std::allocator<char>>);
	virtual int getSyncTasksGroup(void);
	virtual int getIOTasksGroup(void);
	virtual int getClientResourcePackManager(void);
	virtual int getServerResourcePackManager(void);
	virtual int getTradeTables(void);
	virtual void addEntryToTagCache(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void addEntriesToTagCache(std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char>>>>);
	virtual void dropEntryFromTagCache(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void clearTagCache(void);
	virtual void decrementTagCache(); //removed
	virtual void incrementTagCache(); //removed
	virtual bool isEdu(void);
	virtual int getActorFactory(void);
	virtual int getActorFactory2(void);
	virtual int getActorInfoRegistry(void);
	virtual int getEntityRegistryOwner(void);
	virtual int getEntitySystems(void);
	virtual int getLevelEntity(void);
	virtual void _clientHandleAddOwnedEntity(class EntityNetId);
	virtual void _clientHandleAddWeakRefEntity(); //removed
	virtual void _clientHandleRemoveOwnedEntity(EntityNetId);
	virtual void _clientHandleRemoveWeakRefEntity(EntityNetId);
	virtual void runCommand(HashedString const&, class CommandOrigin&, class CommandOriginSystem, class CurrentCmdVersion);
	virtual void runCommand(class Command&, CommandOrigin&, CommandOriginSystem);
	virtual int getTagRegistry(void);
	virtual int getPlayerMovementSettings(void);
	virtual void setPlayerMovementSettings(class PlayerMovementSettings const&);
	virtual void canUseSkin(); //removed
	virtual int getPositionTrackerDBClient(void);
	virtual int getPositionTrackerDBServer(void);
	virtual void flushRunTimeLighting(void);
	virtual void loadBlockDefinitionGroup(Experiments const&);
	virtual void initializeBlockDefinitionGroup(void);
	virtual int getUnknownBlockTypeRegistry(void);
private:
	virtual void TryroFunc300();
public:
	virtual bool isClientSide(void);
	virtual int getPlayerList(void);
	virtual int getPlayerList2(void);
private:
	virtual void TryroFunc304();
	virtual void TryroFunc305();
public:
	virtual int getActiveUsers(void);
	virtual int getRuntimeActorList(void);
	virtual int getGlobalActors(void);
	virtual int getAutonomousActors(void);
	virtual int getAutonomousLoadedEntities(void);
	virtual void removeAutonomousEntity(Actor&, LevelChunk*);
	virtual void notifySubChunkRequestManager(class SubChunkPacket const&);
	virtual int getSubChunkRequestManager(void);
	virtual int getPacketSender(void);
	virtual void setPacketSender(class PacketSender*);
	virtual int getNetEventCallback(void);
	virtual void setNetEventCallback(class NetEventCallback*);
	virtual int getRandom(void);
	virtual int getHitResult(void);
	virtual int getLiquidHitResult(void);
private:
	virtual void TryroFunc321();
public:
	virtual void setImmersiveReaderString(std::basic_string<char, std::char_traits<char>, std::allocator<char>>);
	virtual int getAdventureSettings(void);
	virtual int getGameRules(void);
	virtual int getGameRules2(void);
	virtual void hasStartWithMapEnabled(void);
	virtual int getDefaultAbilities(void);
	virtual int getTearingDown(void);
	virtual void takePicture(); //removed
	virtual int getSoundPlayer(void);
	virtual void setSimPaused(bool);
	virtual int getSimPaused(void);
	virtual void setFinishedInitializing(void);
	virtual int getLootTables(void);
	virtual void updateWeather(float, int, float, int);
	virtual int getNetherScale(void);
	virtual int getScoreboard(void);
	virtual int getPlayerAbilities(uint64_t const&);
	virtual void setPlayerAbilities(uint64_t const&, class Abilities);
	virtual void sendAllPlayerAbilities(Player const&);
	virtual void incrementSpawnableTickedMob(void);
	virtual int getSpawnableTickedMobCountPrevious(void);
	virtual int getRecipes(void);
	virtual int getBlockReducer(void);
	virtual void digestServerBlockProperties(class StartGamePacket const&, class uint);
	virtual void digestServerItemComponents(class ItemComponentPacket const&);
	virtual int getRegisteredBorderBlock(void);
	virtual void asLevel(void);
	virtual void asMultiPlayerLevel(void);
	virtual void onSourceCreated(class BlockSource&);
	virtual void onSourceDestroyed(class BlockSource&);

private:
	char pad_0x0000[0x518]; //0x0000
public:
	std::string WorldName; //0xFB1FE9C0 
private:
	char pad_0x0548[0xA8]; //0x0548
public:
	__int32 TicksPast; //0x05F0 
private:
	char pad_0x05F4[0x3FC]; //0x05F4
public:
	Vector3 EyeHeight; //0x09F0 
	Vector3 LookingVector; //0x09FC 
private:
	char pad_0x0A08[0x4]; //0x0A08
public:
	unsigned char SelectedSide; //0x0A0C 
private:
	char pad_0x0A0D[0xF]; //0x0A0D
public:
	Vector3 LookingPosition; //0x0A1C 
private:
	char pad_0x0A28[0x48]; //0x0A28
public:
	Vector2 CameraRots2; //0x0A70 
	unsigned char LookingAtBlock; //0x0A78 
private:
	char pad_0x0A79[0x3]; //0x0A79
public:
	unsigned char SelectedSide2; //0x0A7C 
private:
	char pad_0x0A7D[0xF]; //0x0A7D
public:
	Vector3 LookingPosition2; //0x0A8C 
};
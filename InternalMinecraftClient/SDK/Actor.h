﻿#pragma once

#include "../Utils/Math.h"
#include "../SDK/Dimension.h"
#include "../SDK/Level.h"
#include "GameMode.h"
#include "../Utils/Utils.h"

class BlockSource {};
class GameMode;

class Actor {
public:
	virtual __int64 getLastHurtByMob(void);
	virtual void setLastHurtByMob(class Mob*);
	virtual __int64 getLastHurtByPlayer(void);
	virtual void setLastHurtByPlayer(Player*);
	virtual __int64 getLastHurtMob(void);
	virtual void setLastHurtMob(Actor*);
	virtual bool outOfWorld(void);
	virtual void reloadHardcoded(); //removed
	virtual void reloadHardcodedClient(); //removed
	virtual void initializeComponents(); //removed
	virtual void reloadComponents(); //removed
	virtual void _serverInitItemStackIds(void);
	virtual void _doInitialMove(void);
	virtual bool hasComponent(class HashedString const&);
private:
	virtual void __PlayerConstructor();
public:
	virtual void reset(void);
	virtual int getOnDeathExperience(void);
	virtual int getOwnerEntityType(void);
	virtual void remove(void);
	virtual void setPos(Vector3 const&);
	virtual bool isRuntimePredictedMovementEnabled(void);
	virtual Vector3* getPredictedMovementValues(void);
	virtual Vector3* getPos(void);
	virtual Vector3* getPosOld(void);
	virtual float getPosExtrapolated(float);
	virtual float getAttachPos(class ActorLocation, float);
	virtual Vector3* getItemFiringPos(void);
	virtual void setRot(Vector2 const&);
	virtual void move(Vector3 const&);
	virtual void move(class IActorMovementProxy&, Vector3 const&);
	virtual float getInterpolatedRidingPosition(float);
	virtual float getInterpolatedBodyRot(float);
	virtual float getInterpolatedHeadRot(float);
	virtual float getInterpolatedBodyYaw(float);
	virtual float getYawSpeedInDegreesPerSecond(void);
	virtual float getInterpolatedWalkAnimSpeed(float);
	virtual float getInterpolatedRidingOffset(float);
	virtual void checkBlockCollisions(); //removed
	virtual void updateEntityInside(AABB const&);
	virtual void updateEntityInside(void);
	virtual bool isFireImmune(void);
	virtual void breaksFallingBlocks(void);
	virtual void blockedByShield(class ActorDamageSource const&, Actor&);
	virtual void teleportTo(Vector3 const&, bool, int, int);
	virtual void tryTeleportTo(Vector3 const&, bool, bool, int, int);
	virtual void chorusFruitTeleport(Vector3 const&);
	virtual void lerpMotion(Vector3 const&);
	virtual void tryCreateAddActorPacket(void);
	virtual void normalTick(void);
	virtual void baseTick(void);
	virtual void vehicleTick(void);
	virtual void positionPassenger(Actor&, float);
	virtual float getRidingHeight(void);
	virtual void startRiding(Actor&);
	virtual void addPassenger(Actor&);
	virtual void flagPassengerToRemove(Actor&);
	virtual TextHolder getExitTip(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, class InputMode);
	virtual void intersects(Vector3 const&, Vector3 const&);
	virtual bool isInWall(void);
	virtual bool isInvisible(void);
	virtual void canShowNameTag(void);
	virtual void canExistInPeaceful(void);
	virtual void setNameTagVisible(bool);
private:
	virtual void TryroFunc67();
public:
	virtual __int64 getNameTagAsHash(void);
	virtual std::string getFormattedNameTag(void);
	virtual void filterFormattedNameTag(class UIProfanityContext const&);
	virtual void setNameTag(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual bool getAlwaysShowNameTag(void);
	virtual void setScoreTag(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
private:
	virtual void TryroFunc74();
public:
	virtual bool isInWater(void);
	virtual void hasEnteredWater(void);
	virtual bool isInLava(void);
	virtual bool isUnderLiquid(class MaterialType);
	virtual bool isOverWater(void);
	virtual void setBlockMovementSlowdownMultiplier(Vector3 const&);
	virtual void resetBlockMovementSlowdownMultiplier(void);
	virtual int getCameraOffset(void);
	virtual int getShadowHeightOffs(void);
	virtual int getShadowRadius(void);
	virtual float getHeadLookVector(float);
	virtual void canSeeInvisible(void);
	virtual void canSee(Actor const&);
	virtual void canSee(Vector3 const&);
	virtual bool isSkyLit(float);
	virtual float getBrightnessAtBlock(float);
	virtual void interactPreventDefault(void);
	virtual void playerTouch(Player&);
	virtual void onAboveBubbleColumn(bool);
	virtual void onInsideBubbleColumn(bool);
	virtual bool isImmobile(void);
	virtual bool isSilent(void);
	virtual bool isPickable(void);
	virtual bool isFishable(void);
	virtual bool isSleeping(void);
	virtual void setSleeping(bool);
	virtual bool isShootable(void);
	virtual void setSneaking(bool);
	virtual bool isBlocking(void);
	virtual bool isDamageBlocked(ActorDamageSource const&);
	virtual bool isAlive(void);
	virtual bool isOnFire(void);
	virtual bool isOnHotBlock(void);
	virtual bool isCreativeModeAllowed(void);
	virtual bool isSurfaceMob(void);
	virtual bool isTargetable(void);
	virtual bool isLocalPlayer(void);
	virtual bool isPlayer(void);
	virtual bool isAffectedByWaterBottle(void);
	virtual void canAttack(Actor*, bool);
	virtual void setTarget(Actor*);
	virtual void findAttackTarget(void);
	virtual bool isValidTarget(Actor*);
	virtual void attack(Actor&, class ActorDamageCause const&);
	virtual void performRangedAttack(Actor&, float);
	virtual void adjustDamageAmount(int&);
	virtual int getEquipmentCount(void);
	virtual void setOwner(uint64_t);
	virtual void setSitting(bool);
	virtual void onTame(void);
	virtual void onFailedTame(void);
	virtual __int64 getInventorySize(void);
	virtual __int64 getEquipSlots(void);
	virtual __int64 getChestSlots(void);
	virtual void setStanding(bool);
	virtual void canPowerJump(void);
	virtual void setCanPowerJump(bool);
	virtual bool isJumping(void);
	virtual bool isEnchanted(void);
	virtual void vehicleLanded(Vector3 const&, Vector3 const&);
	virtual void shouldRender(void);
	virtual void playAmbientSound(void);
	virtual int getAmbientSound(void);
	virtual bool isInvulnerableTo(ActorDamageSource const&);
	virtual __int64 getBlockDamageCause(class Block const&);
	virtual void actuallyHurt(int, ActorDamageSource const&, bool);
	virtual void animateHurt(void);
	virtual void doFireHurt(int);
	virtual void onLightningHit(void);
	virtual void onBounceStarted(class BlockPos const&, Block const&);
	virtual void feed(int);
	virtual void handleEntityEvent(class ActorEvent, int);
	virtual float getPickRadius(void);
	virtual int getActorRendererId(void);
	virtual void spawnAtLocation(int, int);
	virtual void spawnAtLocation(int, int, float);
	virtual void spawnAtLocation(Block const&, int);
	virtual void spawnAtLocation(Block const&, int, float);
	virtual void spawnAtLocation(class ItemStack const&, float);
	virtual void despawn(void);
	virtual void killed(Actor&);
	virtual void awardKillScore(Actor&, int);
	virtual void setArmor(class ArmorSlot, ItemStack const&);
	virtual __int64 getArmor(ArmorSlot);
	virtual __int64 getAllArmor(void);
	virtual __int64 getArmorMaterialTypeInSlot(ArmorSlot);
	virtual __int64 getArmorMaterialTextureTypeInSlot(ArmorSlot);
	virtual __int64 getArmorColorInSlot(ArmorSlot, int);
	virtual __int64 getEquippedSlot(class EquipmentSlot);
	virtual void setEquippedSlot(EquipmentSlot, ItemStack const&);
	virtual __int64 getCarriedItem(void);
	virtual void setCarriedItem(ItemStack const&);
	virtual void setOffhandSlot(ItemStack const&);
	virtual __int64 getEquippedTotem(void);
	virtual void consumeTotem(void);
	virtual void save(class CompoundTag&);
	virtual void saveWithoutId(CompoundTag&);
	virtual void load(CompoundTag const&, class DataLoadHelper&);
	virtual void loadLinks(CompoundTag const&, std::vector<class ActorLink, std::allocator<ActorLink>>&, DataLoadHelper&);
	virtual int getEntityTypeId(void);
	virtual void queryEntityRenderer(void);
	virtual int getSourceUniqueID(void);
	virtual void thawFreezeEffect(void);
	virtual void canFreeze(void);
	virtual bool isWearingLeatherArmor(void);
	virtual AABB getLiquidAABB(MaterialType);
	virtual void handleInsidePortal(BlockPos const&);
	virtual int getPortalCooldown(void);
	virtual int getPortalWaitTime(void);
	virtual int getDimensionId(void);
	virtual void canChangeDimensions(void);
	virtual void changeDimension(); //removed
	virtual void changeDimension(class ChangeDimensionPacket const&);
	virtual class Actor* getControllingPlayer(void);
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float, float, ActorDamageSource);
	virtual void handleFallDistanceOnServer(float, float, bool);
	virtual void playSynchronizedSound(class LevelSoundEvent, Vector3 const&, Block const&, bool);
	virtual void playSynchronizedSound(LevelSoundEvent, Vector3 const&, int, bool);
	virtual void onSynchedFlagUpdate(int, long, long);
	virtual void onSynchedDataUpdate(int);
	virtual void canAddPassenger(Actor&);
	virtual void canPickupItem(ItemStack const&);
	virtual void canBePulledIntoVehicle(void);
	virtual void inCaravan(void);
	virtual bool isLeashableType(void);
	virtual void tickLeash(void);
	virtual void sendMotionPacketIfNeeded(void);
	virtual void canSynchronizeNewEntity(void);
	virtual void stopRiding(bool, bool, bool);
	virtual void startSwimming(void);
	virtual void stopSwimming(void);
	virtual void buildDebugInfo(std::basic_string<char, std::char_traits<char>, std::allocator<char>>&);
	virtual int getCommandPermissionLevel(void);
	virtual bool isClientSide(void);
	virtual __int64 getMutableAttribute(class Attribute const&);
	virtual __int64 getAttribute(class Attribute const&);
	virtual int getDeathTime(void);
	virtual void heal(int);
	virtual bool isInvertedHealAndHarm(void);
	virtual void canBeAffected(int);
	virtual void canBeAffected(class MobEffectInstance const&);
	virtual void canBeAffectedByArrow(MobEffectInstance const&);
	virtual void onEffectAdded(MobEffectInstance&);
	virtual void onEffectUpdated(MobEffectInstance&);
	virtual void onEffectRemoved(MobEffectInstance&);
	virtual __int64 getAnimationComponent(void);
	virtual void openContainerComponent(Player&);
	virtual void swing(void);
	virtual void useItem(class ItemStackBase&, class ItemUseMethod, bool);
	virtual void hasOutputSignal(class uchar);
	virtual __int64 getOutputSignal(void);
	virtual __int64 getDebugText(std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char>>>>&);
	virtual float getMapDecorationRotation(void);
	virtual float getPassengerYRotation(Actor const&);
	virtual float getYHeadRot(void);
	virtual bool isWorldBuilder(void);
	virtual bool isCreative(void);
	virtual bool isAdventure(void);
	virtual void add(ItemStack&);
	virtual void drop(ItemStack const&, bool);
	virtual __int64 getInteraction(Player&, class ActorInteraction&, Vector3 const&);
	virtual void canDestroyBlock(Block const&);
	virtual void setAuxValue(int);
	virtual void setSize(float, float);
	virtual void onOrphan(void);
	virtual void wobble(void);
	virtual void wasHurt(void);
	virtual void startSpinAttack(void);
	virtual void stopSpinAttack(void);
	virtual void setDamageNearbyMobs(bool);
	virtual void renderDebugServerState(class Options const&);
	virtual void reloadLootTable(void);
	virtual void reloadLootTable(class EquipmentTableDefinition const&);
	virtual int getDeletionDelayTimeSeconds(void);
	virtual void kill(void);
	virtual void die(ActorDamageSource const&);
	virtual void shouldDropDeathLoot(void);
	virtual void shouldTick(void);
	virtual void extractSnapshot(class PlayerSnapshotComponent&);
	virtual void applySnapshot(PlayerSnapshotComponent const&, PlayerSnapshotComponent const&);
	virtual float getNextStep(float);
	virtual __int64 getLootTable(void);
	virtual void interpolatorTick(void);
	virtual void updateEntitySpecificMolangVariables(class RenderParams&);
	virtual void shouldTryMakeStepSound(void);
	virtual void canMakeStepSound(void);
	virtual void _hurt(ActorDamageSource const&, int, bool, bool);
	virtual void markHurt(void);
	virtual void _getAnimationComponent(); //removed
	virtual void readAdditionalSaveData(CompoundTag const&, DataLoadHelper&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void _playStepSound(BlockPos const&, Block const&);
	virtual void _playFlySound(BlockPos const&, Block const&);
	virtual void _makeFlySound(void);
	virtual void checkInsideBlocks(float);
	virtual void pushOutOfBlocks(Vector3 const&);
	virtual void updateWaterState(void);
	virtual void doWaterSplashEffect(void);
	virtual void spawnTrailBubbles(void);
	virtual void updateInsideBlock(void);
	virtual void _removePassenger(uint64_t const&, bool, bool, bool);
	virtual void _onSizeUpdated(void);
	virtual void _doAutoAttackOnTouch(Actor&);
	virtual void knockback(Actor*, int, float, float, float, float, float);
	virtual void spawnAnim(void);
	virtual void setSprinting(bool);
	virtual int getHurtSound(void);
	virtual int getDeathSound(void);
	virtual __int64 getItemInHandIcon(ItemStack const&, int);
	virtual float getSpeed(void);
	virtual void setSpeed(float);
	virtual float getJumpPower(void);
	virtual void hurtEffects(ActorDamageSource const&, int, bool, bool);
	virtual float getMeleeWeaponDamageBonus(Actor);
	virtual float getMeleeKnockbackBonus(void);
	virtual void travel(float, float, float);
	virtual void travel(class IMobMovementProxy&, float, float, float);
	virtual void applyFinalFriction(float, bool);
	virtual void updateWalkAnim(void);
	virtual void aiStep(void);
	virtual void aiStep(IMobMovementProxy&);
	virtual void pushActors(void);
	virtual void lookAt(Actor*, float, float);
	virtual bool isLookingAtAnEntity(void);
	virtual void checkSpawnRules(bool);
	virtual void checkSpawnObstruction(void);
	virtual float getAttackAnim(float);
	virtual int getItemUseDuration(void);
	virtual int getItemUseStartupProgress(void);
	virtual int getItemUseIntervalProgress(void);
	virtual int getItemUseIntervalAxis(void);
	virtual int getTimeAlongSwing(void);
	virtual void ate(void);
	virtual int getMaxHeadXRot(void);
	virtual bool isAlliedTo(Actor);
	virtual void doHurtTarget(Actor*, ActorDamageCause const&);
	virtual void canBeControlledByPassenger(void);
	virtual void leaveCaravan(void);
	virtual void joinCaravan(Actor);
	virtual void hasCaravanTail(void);
	virtual __int64 getCaravanHead(void);
	virtual float getArmorValue(void);
	virtual float getArmorCoverPercentage(void);
	virtual void hurtArmorSlots(); //removed
	virtual void setDamagedArmor(ArmorSlot, ItemStack const&);
	virtual void sendArmorDamage(); //removed
	virtual void sendArmor(); //removed
	virtual void containerChanged(int);
	virtual void updateEquipment(void);
	virtual void clearEquipment(void);
	virtual __int64 getAllArmorID(void);
	virtual __int64 getAllHand(void);
	virtual __int64 getAllEquipment(void);
	virtual __int64 getArmorTypeHash(void);
	virtual void dropEquipmentOnDeath(ActorDamageSource const&, int);
	virtual void dropEquipmentOnDeath(void);
	virtual void clearVanishEnchantedItemsOnDeath(void);
	virtual void sendInventory(bool);
	virtual float getDamageAfterMagicAbsorb(ActorDamageSource const&, int);
	virtual void createAIGoals(void);
	virtual void onBorn(Actor&, Actor&);
	virtual void setItemSlot(EquipmentSlot, ItemStack const&);
	virtual void setTransitioningSitting(bool);
	virtual void attackAnimation(Actor*, float);
	virtual int getAttackTime(void);
	virtual void _getWalkTargetValue(BlockPos const&);
	virtual void canExistWhenDisallowMob(void);
	virtual void useNewAi(void);
	virtual void ascendLadder(void);
	virtual void ascendBlockByJumping(void);
	virtual void descendBlockByCrouching(void);
	virtual void dropContainer(void);
	virtual void initBodyControl(void);
	virtual void jumpFromGround(void);
	virtual void jumpFromGround(IMobMovementProxy&);
	virtual void updateAi(void);
	virtual void newServerAiStep(void);
	virtual void _serverAiMobStep(void);
	virtual float getDamageAfterEnchantReduction(ActorDamageSource const&, int);
	virtual float getDamageAfterArmorAbsorb(ActorDamageSource const&, int);
	virtual void dropBags(void);
	virtual void tickDeath(void);
	virtual void updateGliding(void);
	virtual void _allowAscendingScaffolding(void);
	virtual void _getAdjustedAABBForSpawnCheck(AABB const&, Vector3 const&);
	virtual void prepareRegion(); //removed
	virtual void destroyRegion(void);
	virtual void suspendRegion(void);
	virtual void resendAllChunks(void);
	virtual void _fireWillChangeDimension(void);
	virtual void _fireDimensionChanged(void);
	virtual void changeDimensionWithCredits(); //removed
	virtual void tickWorld(); //removed
private:
	virtual void TryroFunc369();
public:
	virtual int getTickingOffsets(void);
	virtual void moveView(void);
	virtual void setName(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void checkMovementStats(Vector3 const&);
	virtual __int64 getCurrentStructureFeature(void);
	virtual bool isAutoJumpEnabled(void);
	virtual void respawn(void);
	virtual void resetRot(void);
	virtual void resetPos(bool);
	virtual bool isInTrialMode(void);
	virtual void hasResource(int);
	virtual void completeUsingItem(void);
	virtual void setPermissions(class CommandPermissionLevel);
	virtual void startDestroying(void);
	virtual void stopDestroying(void);
	virtual void openPortfolio(void);
	virtual void openBook(int, bool, int, class BlockActor*);
	virtual void openTrading(uint64_t const&, bool);
	virtual bool canOpenContainerScreen(void);
	virtual void openChalkboard(class ChalkboardBlockActor&, bool);
	virtual void openNpcInteractScreen(); //removed
	virtual void openInventory(void);
	virtual void displayChatMessage(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void displayClientMessage(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void displayTextObjectMessage(class TextObjectRoot const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void displayTextObjectWhisperMessage(class ResolvedTextObject const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void displayWhisperMessage(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void startSleepInBed(BlockPos const&);
	virtual void stopSleepInBed(bool, bool);
	virtual void canStartSleepInBed(void);
	virtual int getSleepTimer(void);
	virtual int getPreviousTickSleepTimer(void);
	virtual void openSign(BlockPos const&);
	virtual void playEmote(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual bool isHostingPlayer(void);
	virtual bool isLoading(void);
	virtual bool isPlayerInitialized(void);
	virtual void stopLoading(void);
	virtual void registerTrackedBoss(uint64_t);
	virtual void unRegisterTrackedBoss(uint64_t);
	virtual void setPlayerGameType(class GameType);
	virtual void initHUDContainerManager(void);
	virtual void _crit(Actor&);
	virtual __int64 getEventing(void);
	virtual int getUserId(void);
	virtual void sendEventPacket(class EventPacket&);
	virtual void addExperience(int);
	virtual void addLevels(int);
	// lp funcs
private:
	virtual void TryroFunc416();
	virtual void TryroFunc417();
public:
	virtual void inventoryChanged(uintptr_t Container, int, ItemStack const&, ItemStack const&, bool);
private:
	virtual void TryroFunc419();
public:
	virtual void deleteContainerManager(void);
	virtual void setFieldOfViewModifier(float);
	virtual bool is2DPositionRelevant();
	virtual bool isEntityRelevant(Actor const&);
private:
	virtual void TryroFunc424();
public:
	virtual void onSuspension(void);
	virtual void onLinkedSlotsChanged(void);
	virtual void startCooldown(__int64 const* Item);
	virtual int getItemCooldownLeft(void* hashedstring);
	virtual int getItemCooldownLeft(ULONG);
	virtual int getMaxItemCooldownLeft(void);
	virtual bool isItemInCooldown(void* hashedstring);
private:
	virtual void TryroFunc432();
	virtual void TryroFunc433();
public:
	virtual void sendNetworkPacket(void* Packet);
private:
	virtual void TryroFunc435();
	virtual void TryroFunc436();
	virtual void TryroFunc437();
	virtual void TryroFunc438();
public:
	virtual void reportMovementTelemetry(void* MovementEventType);
	virtual bool isSimulated(void);
	virtual TextHolder getXUID(void);
	virtual __int64 getMovementSettings(void);
	virtual void onMovePlayerPacketNormal(class Vector3 const&, class Vector2 const&, float);
	virtual void _createChunkSource(void* ChunkSource);

private: // Variables - 0x8 (Vtable ptr)
	char pad_0x0008[0xF8]; //0x0008

	//isBaby -> 0x11

public:
	bool InLove; //0x0100 
private:// 0x100
	char pad_0x0101[0x37]; //0x0101
public:
	Vector2 CameraRots; //0x0138 
	Vector2 CameraRotsBefore; //0x0140 
private:
	char pad_0x0148[0x10]; //0x0148
public:
	Vector3 eyeHeight; //0x0158 
private:
	char pad_0x0164[0x70]; //0x0164
public:
	float fallDistance; //0x01D4 
	bool onGround; //0x01D8 
	bool onGround2; //0x01D9 
	bool walkingIntoObj; //0x01DA 
	bool onGround3; //0x01DB 
	bool TouchingObj; //0x01DC 
private:
	char pad_0x01DD[0x5B]; //0x01DD
public:
	float stepHeight; //0x0238 
private:
	char pad_0x023C[0x4]; //0x023C
public:
	float touchingObjWalkDistance; //0x0240 
	float touchingObjWalkDistanceBefore; //0x0244 
	float blocksTraveled; //0x0248 
	Vector3 SlowDown; //0x024C 
	float blocksTraveledExc; //0x0258 
	bool ImmersedInWater; //0x025C 
	bool IsInWater; //0x025D 
	bool HasEnteredWater; //0x025E (Got this from ida btw)
	bool IsSwimming; //0x025F 
private:
	char pad_0x0260[0x48]; //0x0260
public:
	Vector3 HurtTime; //0x02A8 
private: // 0x2B0
	char pad_0x02B4[0x1]; //0x02B4
public:
	bool CameraShake; //0x02B5 
private:
	char pad_0x02B6[0xA2]; //0x02B6
public:
	BlockSource* blockSource; //0x0358 
	Dimension* dimension; //0x0360 
	Level* level; //0x0368 
private:
	char pad_0x0370[0x148]; //0x0370
public:
	AABB Position; //0x04B8 
	Vector2 Hitbox; //0x04D0 
	AABB Camera; //0x04D8 
	Vector3 Velocity; //0x04F0 
	Vector3 Velocity2; //0x04FC 
private:
	char pad_0x0508[0x238]; //0x0508
public:
	Vector2 BodyRotations; //0x0740 
	Vector2 FirstPersonHandRotations; //0x0748 
private:
	char pad_0x0750[0x21C]; //0x0750
public:
	bool CanTakeDamage; //0x096C 
private:
	char pad_0x096D[0xB]; //0x096D
public:
	bool IsFlying; //0x0978 
private:
	char pad_0x0979[0x17]; //0x0979
public:
	bool InfResources; //0x0990 

public: // Functions
	// Returns the memory instance of GameMode
	class GameMode* getGamemode() {
		return *reinterpret_cast<class GameMode**>(reinterpret_cast<__int64>(this) + 0x1248);
	};

	// Someone make these classes

	__int64* getLevel() {
		return *reinterpret_cast<__int64**>(reinterpret_cast<__int64>(this) + 0x368);
	};

	__int64* getDimension() {
		return *reinterpret_cast<__int64**>(reinterpret_cast<__int64>(this) + 0x360);
	};

	__int64* getBlockSource() {
		return *reinterpret_cast<__int64**>(reinterpret_cast<__int64>(this) + 0x358);
	};

	__int64* getInventory() {
		return *reinterpret_cast<__int64**>(reinterpret_cast<__int64>(this) + 0xB88);
	};

	void SetRenderPosition(Vector3 v) {
		Camera.lower = v;
		Camera.upper = v;
	}

	float* SwingAnimation() {
		return reinterpret_cast<float*>((uintptr_t)(this) + 0x7C0);
	}
	/*
	void lerpybutworky(Vector3 motion) { //if someone changes the name im gonna steal your knee caps
		using lerpMotion2 = void(__thiscall*)(void*, Vector3);
		static lerpMotion2 lerpy = reinterpret_cast<lerpMotion2>(Mem::findSig("8B 02 89 81 F8 04 00 00 8B 42 04 89 81 FC 04 00 00 8B 42 08 89 81 00 05 00 00 C3 CC"));
		lerpy(this, motion);
	}
	*/
	/*float getHealth() {
		return *reinterpret_cast<float*>(this + Mem::findSig("48 83 EC 28 48 8B 01 48 8D 15 EA D6 41 02 FF 90 78 06 00 00 F3 0F 10 80 84 00 00 00 48 83 C4 28 C3 CC"));
	}*/
	void SetFieldOfView(float v) {
		//*(float*)((uintptr_t)(this) + 0x10F0) = v;
		*(float*)((uintptr_t)(this) + 0x1050) = v;
		//*(float*)((uintptr_t)(this) + 0x1140) = v;
	}

	float FieldOfView() {
		return *reinterpret_cast<float*>(this + 0x1050);
	}

	/*void SetPitch(float v) {
		*(float*)((uintptr_t)(this) + 0x0138) = v;
	}

	void SetYaw(float v) {
		*(float*)((uintptr_t)(this) + 0x013C) = v;
	}

	void SetBodyYaw(float v) {
		*(float*)((uintptr_t)(this) + 0x0748) = v;
	}

	void SetBodyYaw2(float v) {
		*(float*)((uintptr_t)(this) + 0x074C) = v;
	}

	void SetWeirdYaw(float v) {
		*(float*)((uintptr_t)(this) + 0x0750) = v;
	}

	void SetRlyWeirdYaw(float v) {
		*(float*)((uintptr_t)(this) + 0x0754) = v;
	}*/

	PDWORD disposable;
	float SetReach(float v) {
		uintptr_t reachAddr = Mem::findSig("F3 0F 10 05 ?? ?? ?? ?? 41 0F 28 D9");
		VirtualProtect((LPVOID*)reachAddr, sizeof(float), PAGE_EXECUTE_READWRITE, disposable); // i hate visual studio in general
		auto reach = *reinterpret_cast<float*>(reachAddr);
		v = reach;
		return v;
	}

	Vector2* bodyRots() {
		return reinterpret_cast<Vector2*>((uintptr_t)(this) + 0x138);
	}

	std::string Nametag() {
		return ((TextHolder*)((uintptr_t)(this) + 0x8D8))->getText();
	}

	std::string getType() {
		return ((TextHolder*)((uintptr_t)(this) + 0x3F8))->getText();
	}

	std::string getName()
	{
		std::string name = this->getFormattedNameTag();
		if (name.length() == 0) {
			if (this->isPlayer())
				name = this->Nametag();
			else
				name = this->getType();
		}

		return name;
	}

	void setShadowRadius(float v) {
		*(float*)((uintptr_t)(this) + 0x04D0) = v;
	}

	void test(float v) {
		*(float*)((uintptr_t)(this) + 0x0818) = v;
		*(float*)((uintptr_t)(this) + 0x07A8) = v;
	}

	// Reset this actor's vertical velocity
	void resetVerticalVelocity()
	{
		this->Velocity.y = 0.f;
	}

	// Reset this actor's horizontal velocity
	void resetHorizontalVelocity()
	{
		this->Velocity.x = 0.f;
		this->Velocity.z = 0.f;
	}

	// Reset full velocity
	void resetVelocity()
	{
		this->resetVerticalVelocity();
		this->resetHorizontalVelocity();
	}

	// Returns vTable
	uintptr_t** vTable()
	{
		return reinterpret_cast<uintptr_t**>((uintptr_t*)(this) + 0x0);
	}

	int getPlayerGameType() {
		return *reinterpret_cast<int*>(this + 0x1D8C);
	}
};

class ContainerManagement {
public:
	void shiftClickItems(std::string containerName, int slots) {
		static auto shiftClickItem = reinterpret_cast<__int64(__fastcall*)(ContainerManagement*, uintptr_t, TextHolder, int)>(Mem::findSig("40 55 53 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 ? 45 8B E1 49 8B F0 44 8B EA"));
		shiftClickItem(this, 0x7FFFFFFF, containerName, slots);
	}
	
	void closeContainer() {
		static auto closeThingy = reinterpret_cast<__int64(__fastcall*)(ContainerManagement*)>(Mem::findSig("48 89 5C 24 10 48 89 7C 24 18 55 48 8D 6C 24 A9 48 81 EC C0 00 00 00 48 8B F9 48 8B 01 FF 50 50"));
		closeThingy(this);
	}
};


#pragma once

#include "../Utils/Math.h"
#include "../SDK/Dimension.h"
#include "../SDK/Level.h"
#include "GameMode.h"
#include "../Utils/Utils.h"

class BlockSource {};
class GameMode;

class Actor {
private:
		virtual void setLastHurtByMob(class Mob*);
		virtual int getLastHurtByPlayer(void);
		virtual void setLastHurtByPlayer(Player*);
		virtual int getLastHurtMob(void);
		virtual void setLastHurtMob(Actor*);
		virtual void outOfWorld(void);
		virtual void reloadHardcoded(); // removed
		virtual void reloadHardcodedClient(); // removed
		virtual void initializeComponents(); // removed
		virtual void reloadComponents(); // removed
		virtual void _serverInitItemStackIds(void);
		virtual void _doInitialMove(void);
		virtual void hasComponent(class HashedString const&);
	private:
		virtual void Constructor3();
		virtual void Constructor4();
	public:
		virtual void reset(void);
		virtual int getOnDeathExperience(void);
		virtual int getOwnerEntityType(void);
		virtual void remove(void);
		virtual void setPos(Vector3 const&);
		virtual bool isRuntimePredictedMovementEnabled(void);
		virtual int getPredictedMovementValues(void);
		virtual int getPos(void);
		virtual int getPosOld(void);
		virtual float getPosExtrapolated(float);
		virtual float getAttachPos(class ActorLocation, float);
		virtual int getFiringPos(void);
		virtual void setRot(Vector2 const&);
		virtual void move(Vector3 const&);
		virtual void move(class IActorMovementProxy&, Vector3 const&);
		virtual float getInterpolatedRidingPosition(float);
		virtual float getInterpolatedBodyRot(float);
		virtual float getInterpolatedHeadRot(float);
		virtual float getInterpolatedBodyYaw(float);
		virtual int getYawSpeedInDegreesPerSecond(void);
		virtual float getInterpolatedWalkAnimSpeed(float);
		virtual float getInterpolatedRidingOffset(float);
		virtual void checkBlockCollisions(); // removed
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
		virtual int getRidingHeight(void);
		virtual void startRiding(Actor&);
		virtual void addPassenger(Actor&);
		virtual void flagPassengerToRemove(Actor&);
		virtual int getExitTip(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, class InputMode);
		virtual void intersects(Vector3 const&, Vector3 const&);
		virtual bool isInWall(void);
		virtual bool isInvisible(void);
		virtual void canShowNameTag(void);
		virtual void canExistInPeaceful(void);
		virtual void setNameTagVisible(bool);
	private:
		virtual void TryroFunc67();
	public:
		virtual int getNameTagAsHash(void);
	private:
		virtual void TryroFunc69();
	public:
		virtual void filterFormattedNameTag(class UIProfanityContext const&);
		virtual void setNameTag(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
		virtual int getAlwaysShowNameTag(void);
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
		virtual float getBrightness(float);
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
		virtual bool isDamageBlocked(class ActorDamageSource const&);
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
		virtual void attack(Actor&); // tf
		virtual void performRangedAttack(Actor&, float);
		virtual void adjustDamageAmount(int&);
		virtual int getEquipmentCount(void);
		virtual void setOwner(uint64_t);
		virtual void setSitting(bool);
		virtual void onTame(void);
		virtual void onFailedTame(void);
		virtual int getInventorySize(void);
		virtual int getEquipSlots(void);
		virtual int getChestSlots(void);
		virtual void setStanding(bool);
		virtual void canPowerJump(void);
		virtual void setCanPowerJump(bool);
		virtual bool isJumping(void);
		virtual bool isEnchanted(void);
		virtual void vehicleJumped(void);
		virtual void vehicleLanded(Vector3 const&, Vector3 const&);
		virtual void shouldRender(void);
		virtual void playAmbientSound(void);
		virtual int getAmbientSound(void);
		virtual bool isInvulnerableTo(ActorDamageSource const&);
		virtual int getBlockDamageCause(class Block const&);
		virtual void actuallyHurt(int, ActorDamageSource const&, bool);
		virtual void animateHurt(void);
		virtual void doFireHurt(int);
		virtual void onLightningHit(void);
		virtual void onBounceStarted(class BlockPos const&, class Block const&);
		virtual void feed(int);
		virtual void handleEntityEvent(class ActorEvent, int);
		virtual int getPickRadius(void);
		virtual int getActorRendererId(void);
		virtual void spawnAtLocation(int, int);
		virtual void spawnAtLocation(int, int, float);
		virtual void spawnAtLocation(class Block const&, int);
		virtual void spawnAtLocation(class Block const&, int, float);
		virtual void spawnAtLocation(class ItemStack const&, float);
		virtual void despawn(void);
		virtual void killed(Actor&);
		virtual void awardKillScore(Actor&, int);
		virtual void setArmor(class ArmorSlot, ItemStack const&);
		virtual int getArmor(ArmorSlot);
		virtual int getArmorMaterialTypeInSlot(ArmorSlot);
		virtual int getArmorMaterialTextureTypeInSlot(ArmorSlot);
		virtual int getArmorColorInSlot(ArmorSlot, int);
		virtual int getEquippedSlot(class EquipmentSlot);
		virtual void setEquippedSlot(class EquipmentSlot, ItemStack const&);
		virtual int getCarriedItem(void);
		virtual void setCarriedItem(ItemStack const&);
		virtual void setOffhandSlot(ItemStack const&);
		virtual int getEquippedTotem(void);
		virtual void consumeTotem(void);
		virtual void save(class CompoundTag&);
		virtual void saveWithoutId(class CompoundTag&);
		virtual void load(class CompoundTag const&, class DataLoadHelper&);
		virtual void loadLinks(); // removed
		virtual int getEntityTypeId(void);
		virtual void queryEntityRenderer(void);
		virtual int getSourceUniqueID(void);
		virtual void setOnFire(int);
		virtual void extinguishFire(void);
		virtual void thawFreezeEffect(void);
		virtual void canFreeze(void);
		virtual bool isWearingLeatherArmor(void);
		virtual int getLiquidAABB(MaterialType);
		virtual void handleInsidePortal(BlockPos const&);
		virtual int getPortalCooldown(void);
		virtual int getPortalWaitTime(void);
		virtual int getDimensionId(void);
		virtual void canChangeDimensions(void);
		virtual void changeDimension(); // removed
		virtual void changeDimension2(class ChangeDimensionPacket const&);
		virtual int getControllingPlayer(void);
		virtual void checkFallDamage(float, bool);
		virtual void causeFallDamage(float, float, ActorDamageSource);
		virtual void handleFallDistanceOnServer(float, float, bool);
		virtual void playSynchronizedSound(class LevelSoundEvent, Vector3 const&, Block const&, bool);
		virtual void playSynchronizedSound(LevelSoundEvent, Vector3 const&, int, bool);
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
		virtual int getMutableAttribute(class Attribute const&);
		virtual int getAttribute(class Attribute const&);
		virtual int getDeathTime(void);
		virtual void heal(int);
		virtual bool isInvertedHealAndHarm(void);
		virtual void canBeAffected(int);
		virtual void canBeAffected(class MobEffectInstance const&);
		virtual void canBeAffectedByArrow(class MobEffectInstance const&);
		virtual void onEffectAdded(class MobEffectInstance&);
		virtual void onEffectUpdated(MobEffectInstance&);
		virtual void onEffectRemoved(MobEffectInstance&);
		virtual int getAnimationComponent(void);
		virtual void openContainerComponent(Player&);
		virtual void swing(void);
		virtual void useItem(class ItemStackBase&, class ItemUseMethod, bool);
		virtual void hasOutputSignal(char*);
		virtual int getOutputSignal(void);
		virtual int getDebugText(std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char>>>>&);
		virtual int getMapDecorationRotation(void);
		virtual int getPassengerYRotation(Actor const&);
		virtual int getYHeadRot(void);
		virtual bool isWorldBuilder(void);
		virtual bool isCreative(void);
		virtual bool isAdventure(void);
		virtual void add(ItemStack&);
		virtual void drop(ItemStack const&, bool);
		virtual int getInteraction(Player&, class ActorInteraction&, Vector3 const&);
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
		virtual void applySnapshot(class PlayerSnapshotComponent const&, class PlayerSnapshotComponent const&);
		virtual float getNextStep(float);
		virtual int getLootTable(void);
		virtual void interpolatorTick(void);
		virtual void updateEntitySpecificMolangVariables(class RenderParams&);
		virtual void shouldTryMakeStepSound(void);
		virtual void canMakeStepSound(void);
		virtual void _hurt(ActorDamageSource const&, int, bool, bool);
		virtual void markHurt(void);
		virtual void _getAnimationComponent(); // removed
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
		virtual int getItemInHandIcon(ItemStack const&, int);
		virtual int getSpeed(void);
		virtual void setSpeed(float);
		virtual int getJumpPower(void);
		virtual void hurtEffects(ActorDamageSource const&, int, bool, bool);
		virtual int getMeleeWeaponDamageBonus(Actor);
		virtual int getMeleeKnockbackBonus(void);
		virtual void travel(float, float, float);
		virtual void travel(class IMobMovementProxy&, float, float, float);
		virtual void applyFinalFriction(float, bool);
		virtual void updateWalkAnim(void);
		virtual void aiStep(void);
		virtual void aiStep2(class IMobMovementProxy&);
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
		virtual void doHurtTarget(Actor*, class ActorDamageCause const&);
		virtual void canBeControlledByPassenger(void);
		virtual void leaveCaravan(void);
		virtual void joinCaravan(Actor);
		virtual void hasCaravanTail(void);
		virtual int getCaravanHead(void);
		virtual int getArmorValue(void);
		virtual int getArmorCoverPercentage(void);
		virtual void hurtArmorSlots(); // removed
		virtual void setDamagedArmor(class ArmorSlot, class ItemStack const&);
		virtual void sendArmorDamage(); // removed
		virtual void sendArmor(); // removed
		virtual void containerChanged(int);
		virtual void updateEquipment(void);
		virtual void clearEquipment(void);
		virtual int getAllArmor(void);
		virtual int getAllArmorID(void);
		virtual int getAllHand(void);
		virtual int getAllEquipment(void);
		virtual int getArmorTypeHash(void);
		virtual void dropEquipmentOnDeath(ActorDamageSource const&, int);
		virtual void dropEquipmentOnDeath(void);
		virtual void clearVanishEnchantedItemsOnDeath(void);
		virtual void sendInventory(bool);
		virtual int getDamageAfterMagicAbsorb(ActorDamageSource const&, int);
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
		virtual void jumpFromGround2(class IMobMovementProxy&);
		virtual void updateAi(void);
		virtual void newServerAiStep(void);
		virtual void _serverAiMobStep(void);
		virtual int getDamageAfterEnchantReduction(ActorDamageSource const&, int);
		virtual int getDamageAfterArmorAbsorb(ActorDamageSource const&, int);
		virtual void dropBags(void);
		virtual void tickDeath(void);
		virtual void updateGliding(void);
		virtual void _allowAscendingScaffolding(void);
		virtual void prepareRegion(class ChunkSource&);
		virtual void destroyRegion(void);
		virtual void suspendRegion(void);
		virtual void resendAllChunks(void);
		virtual void _fireWillChangeDimension(void);
		virtual void _fireDimensionChanged(void);
		virtual void changeDimensionWithCredits(); // removed
		virtual void tickWorld(class Tick const&);
	private:
		virtual void TryroFunc370();
	public:
		virtual int getTickingOffsets(void);
		virtual void moveView(void);
		virtual void setName(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
		virtual void checkMovementStats(Vector3 const&);
		virtual int getCurrentStructureFeature(void);
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
		virtual void openNpcInteractScreen(); // removed
		virtual void openInventory(void);
		virtual void displayChatMessage(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
		virtual void displayClientMessage(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
		virtual void displayTextObjectMessage(TextHolder const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
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
		virtual int getEventing(void);
		virtual int getUserId(void);
		virtual void sendEventPacket(class EventPacket&);
		virtual void addExperience(int);
		virtual void addLevels(int);
	private:
		virtual void TryroFunc419();
		virtual void TryroFunc420();
	public:
		virtual void inventoryChanged(class Container&, int, class ItemStack const&, class ItemStack const&, bool);
	private:
		virtual void TryroFunc422();
	public:
		virtual void deleteContainerManager(void);
		virtual void setFieldOfViewModifier(float);
		virtual bool is2DPositionRelevant(); // removed
		virtual bool isActorRelevant(Actor const&);
	private:
		virtual void TryroFunc427();
	public:
		virtual void onSuspension(void);
		virtual void onLinkedSlotsChanged(void);
		virtual void startCooldown(class Item const*);
		virtual int getItemCooldownLeft(HashedString const&);
		virtual int getItemCooldownLeft(uintptr_t);
		virtual int getMaxItemCooldownLeft(void);
		virtual bool isItemInCooldown(HashedString const&);
	private:
		virtual void TryroFunc435();
		virtual void TryroFunc436();
	public:
		virtual void sendNetworkPacket(Packet&);
	private:
		virtual void TryroFunc438();
		virtual void TryroFunc439();
		virtual void TryroFunc440();
		virtual void TryroFunc441();
	public:
		virtual void reportMovementTelemetry(class MovementEventType);
		virtual bool isSimulated(void);
	private:
		virtual void TryroFunc444();
	public:
		virtual int getMovementSettings(void);
		virtual void onMovePlayerPacketNormal(Vector3 const&, Vector2 const&, float);
		virtual void _createChunkSource(ChunkSource&);

private: // Variables - 0x8 (Vtable ptr)
	char pad_0x0000[0x100 - 0x8]; //0x0000
public:
	__int8 CameraCanMove; //0x0100 
private:
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
	unsigned char onGround; //0x01D8 
	unsigned char onGround2; //0x01D9 
	unsigned char walkingIntoObj; //0x01DA 
	unsigned char onGround3; //0x01DB 
	unsigned char TouchingObj; //0x01DC 
private:
	char pad_0x01DD[0x4F]; //0x01DD
public:
	float CameraRenderHeight; //0x022C 
private:
	char pad_0x0230[0x8]; //0x0230
public:
	float stepHeight; //0x0238 
	float nullObj_0x023C; //0x023C 
	float touchingObjWalkDistance; //0x0240 
	float touchingObjWalkDistanceBefore; //0x0244 
	float blocksTraveled; //0x0248 
	Vector3 SlowDown; //0x024C 
	float blocksTraveledExc; //0x0258 
private:
	char pad_0x025C[0x1]; //0x025C
public:
	unsigned char IsInWater; //0x025D 
private:
	char pad_0x025E[0x4A]; //0x025E
public:
	__int32 HurtTime; //0x02A8 
	__int32 HurtTimeAnimation; //0x02AC 
private:
	char pad_0x02B0[0x19]; //0x02B0
public:
	unsigned char IsInLava; //0x02C9 
private:
	char pad_0x02CA[0x76]; //0x02CA
public:
	float playerAnimationPlaybackSpeed; //0x0340 
private:
	char pad_0x0344[0x1C]; //0x0344
public:
	BlockSource* blockSource; //0x0360
	Dimension* dimension; //0x0368
	Level* level; //0x0370
private:
	char pad_0x0378[0x88]; //0x0378
public:
	char EntityType[64]; //0xAE3E8838
private:
	char pad_0x0440[0x80]; //0x0440
public:
	AABB Position; //0x04C0
	Vector2 Hitbox; //0x04D8
	AABB Camera; //0x04E0
	Vector3 Velocity; //0x04F8
	Vector3 Velocity2; //0x0504
private:
	char pad_0x0510[0x3C0]; //0x0510
public:
	__int64 IsAfk; //0x08D0
private:
	char pad_0x08D8[0x8]; //0x08D8
public:
	std::string Username; //0xCE89EF28
private:
	char pad_0x0900[0x80]; //0x0900
public:
	unsigned char IsFlying; //0x0980 
private:
	char pad_0x0981[0xB]; //0x0981
public:
	unsigned char CanFly; //0x098C 
private:
	char pad_0x098D[0x23F]; //0x098D
public: // 1.17.34 im unsure how to find nor where gamemode is rn sorry lol
	GameMode* gameMode; //0x0BCC 
private:
	char pad_0x0BD4[0x484]; //0x0BD4
	float N0000020C; //0x1058 
	char pad_0x105C[0xEC]; //0x105C
public:
	unsigned char InInventory; //0x1148
private:
	char pad_0x1149[0xD23]; //0x1149
public:
	unsigned char Gamemode; //0x1E6C
	//gamemode is actually 0x1D84
public: // Functions
	void SetRenderPosition(Vector3 v) {
		Camera.lower = v;
		Camera.upper = v;
	}

	float* SwingAnimation() {
		return reinterpret_cast<float*>((uintptr_t)(this) + 0x7C8);
	}
	/*
	void lerpybutworky(Vector3 motion) { //if someone changes the name im gonna steal your knee caps
		using lerpMotion2 = void(__thiscall*)(void*, Vector3);
		static lerpMotion2 lerpy = reinterpret_cast<lerpMotion2>(Mem::findSig("8B 02 89 81 F8 04 00 00 8B 42 04 89 81 FC 04 00 00 8B 42 08 89 81 00 05 00 00 C3 CC"));
		lerpy(this, motion);
	}
	*/
	void SetFieldOfView(float v) {
		//*(float*)((uintptr_t)(this) + 0x10F0) = v;
		*(float*)((uintptr_t)(this) + 0x1058) = v;
		//*(float*)((uintptr_t)(this) + 0x1140) = v;
	}

	float FieldOfView() {
		return *reinterpret_cast<float*>(this + 0x1058);
	}

	void SetPitch(float v) {
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
	}

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

	void setGamemode(int gamemode) {
		*(int*)((uintptr_t)(this) + 0x1D84) = gamemode;
	}

	int getGamemode() {
		return *reinterpret_cast<int*>(this + 0x1D84);
	}
};
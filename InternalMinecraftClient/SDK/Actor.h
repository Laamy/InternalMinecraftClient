#pragma once

#include "../Utils/Math.h"
#include "../SDK/Dimension.h"
#include "../SDK/Level.h"
#include "GameMode.h"

class BlockSource {};

class Actor {
public:
	virtual int getLastHurtByMob(void);
private:
	virtual void setLastHurtByMob(class Mob*);
public:
	virtual int getLastHurtByPlayer(void);
	virtual void setLastHurtByPlayer(class Player*);
	virtual int getLastHurtMob(void);
	virtual void setLastHurtMob(Actor*);
	virtual void outOfWorld(void);
private:
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
public:
	virtual void _doInitialMove(void);
private:
	virtual void Function13();
	virtual void Function14();
	virtual void Function15();
public:
	virtual void reset(void);
	virtual int getOnDeathExperience(void);
	virtual int getOwnerEntityType(void);
	virtual void remove(void);
	virtual void setPos(struct Vec3 const&);
	virtual bool isRuntimePredictedMovementEnabled(void);
	virtual int getPredictedMovementValues(void);
	virtual int getPos(void);
	virtual int getPosOld(void);
	virtual float getPosExtrapolated(float);
private:
	virtual void Function26();
public:
	virtual int getFiringPos(void);
	virtual void setRot(struct Vec2 const&);
	virtual void move(struct Vec3 const&);
private:
	virtual void Function30();
public:
	virtual float getInterpolatedRidingPosition(float);
	virtual float getInterpolatedBodyRot(float);
	virtual float getInterpolatedHeadRot(float);
	virtual float getInterpolatedBodyYaw(float);
	virtual int getYawSpeedInDegreesPerSecond(void);
	virtual float getInterpolatedWalkAnimSpeed(float);
	virtual float getInterpolatedRidingOffset(float);
private:
	virtual void Function38();
	virtual void Function39();
public:
	virtual void updateEntityInside(void);
	virtual bool isFireImmune(void);
private:
	virtual void Function42();
	virtual void Function43();
public:
	virtual void teleportTo(struct Vec3 const&, bool, int, int);
	virtual void tryTeleportTo(struct Vec3 const&, bool, bool, int, int);
	virtual void chorusFruitTeleport(struct Vec3 const&);
	virtual void lerpMotion(struct Vec3 const&);
	virtual void tryCreateAddActorPacket(void);
private:
	virtual void Function49();
	virtual void Function50();
	virtual void Function51();
public:
	virtual void positionPassenger(Actor&, float);
	virtual int getRidingHeight(void);
	virtual void startRiding(Actor&);
	virtual void addPassenger(Actor&);
	virtual void flagPassengerToRemove(Actor&);
private:
	virtual int getExitTip(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, class InputMode);
public:
	virtual void intersects(struct Vec3 const&, struct Vec3 const&);
	virtual bool isInWall(void);
	virtual bool isInvisible(void);
	virtual void canShowNameTag(void);
	virtual void canExistInPeaceful(void);
	virtual void setNameTagVisible(bool);
private:
	virtual void Function64();
public:
	virtual int getNameTagAsHash(void);
private:
	virtual void Function66();
	virtual void Function67();
public:
	virtual void setNameTag(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual int getAlwaysShowNameTag(void);
	virtual void setScoreTag(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
private:
	virtual void Function71();
public:
	virtual bool isInWater(void);
	virtual void hasEnteredWater(void);
	virtual bool isInLava(void);
private:
	virtual void Function75();
public:
	virtual bool isOverWater(void);
private:
	virtual void Function77();
	virtual void Function78();
public:
	virtual int getCameraOffset(void);
	virtual int getShadowHeightOffs(void);
	virtual int getShadowRadius(void);
	virtual float getHeadLookVector(float);
	virtual void canSeeInvisible(void);
	virtual void canSee(Actor const&);
	virtual void canSee(struct Vec3 const&);
	virtual bool isSkyLit(float);
	virtual float getBrightness(float);
	virtual void interactPreventDefault(void);
private:
	virtual void playerTouch(class Player&);
public:
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
private:
	virtual void Function100();
	virtual void Function101();
public:
	virtual bool isAlive(void);
	virtual bool isOnFire(void);
private:
	virtual void Function104();
public:
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
	virtual int getInventorySize(void);
	virtual int getEquipSlots(void);
	virtual int getChestSlots(void);
	virtual void setStanding(bool);
	virtual void canPowerJump(void);
	virtual void setCanPowerJump(bool);
	virtual bool isJumping(void);
	virtual bool isEnchanted(void);
	virtual void vehicleJumped(void);
	virtual void vehicleLanded(struct Vec3 const&, struct Vec3 const&);
	virtual void shouldRender(void);
	virtual void playAmbientSound(void);
	virtual int getAmbientSound(void);
private:
	virtual void Function136();
	virtual void Function137();
	virtual void Function138();
public:
	virtual void animateHurt(void);
	virtual void doFireHurt(int);
	virtual void onLightningHit(void);
private:
	virtual void Function142();
public:
	virtual void feed(int);
private:
	virtual void Function144();
public:
	virtual int getPickRadius(void);
	virtual int getActorRendererId(void);
	virtual void spawnAtLocation(int, int);
	virtual void spawnAtLocation(int, int, float);
private:
	virtual void Function149();
	virtual void Function150();
	virtual void Function151();
public:
	virtual void despawn(void);
	virtual void killed(Actor&);
	virtual void awardKillScore(Actor&, int);
private:
	virtual void Function155();
	virtual void Function156();
	virtual void Function157();
	virtual void Function158();
	virtual void Function159();
	virtual void Function160();
	virtual void Function161();
	virtual void Function162();
	virtual void Function163();
	virtual void Function164();
public:
	virtual int getEquippedTotem(void);
	virtual void consumeTotem(void);
private:
	virtual void save(class CompoundTag&);
	virtual void saveWithoutId(class CompoundTag&);
	virtual void load(class CompoundTag const&, class DataLoadHelper&);
	virtual void Function170();
public:
	virtual int getEntityTypeId(void);
	virtual void queryEntityRenderer(void);
	virtual int getSourceUniqueID(void);
	virtual void setOnFire(int);
	virtual void extinguishFire(void);
	virtual void thawFreezeEffect(void);
	virtual void canFreeze(void);
	virtual bool isWearingLeatherArmor(void);
private:
	virtual void Function179();
	virtual void Function180();
public:
	virtual int getPortalCooldown(void);
	virtual int getPortalWaitTime(void);
	virtual int getDimensionId(void);
	virtual void canChangeDimensions(void);
private:
	virtual void Function185();
	virtual void Function186();
public:
	virtual int getControllingPlayer(void);
	virtual void checkFallDamage(float, bool);
private:
	virtual void Function189();
public:
	virtual void handleFallDistanceOnServer(float, float, bool);
private:
	virtual void Function191();
	virtual void Function192();
public:
	virtual void onSynchedDataUpdate(int);
	virtual void canAddPassenger(Actor&);
private:
	virtual void Function195();
public:
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
private:
	virtual void Function206();
public:
	virtual bool isClientSide(void);
private:
	virtual void Function208();
	virtual void Function209();
public:
	virtual int getDeathTime(void);
	virtual void heal(int);
	virtual bool isInvertedHealAndHarm(void);
	virtual void canBeAffected(int);
private:
	virtual void Function214();
	virtual void Function215();
	virtual void Function216();
	virtual void Function217();
	virtual void Function218();
public:
	virtual int getAnimationComponent(void);
private:
	virtual void Function220();
public:
	virtual void swing(void);
private:
	virtual void Function222();
	virtual void Function223();
public:
	virtual int getOutputSignal(void);
	virtual int getDebugText(std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char>>>>&);
	virtual int getMapDecorationRotation(void);
	virtual int getPassengerYRotation(Actor const&);
	virtual int getYHeadRot(void);
	virtual bool isWorldBuilder(void);
	virtual bool isCreative(void);
	virtual bool isAdventure(void);
private:
	virtual void Function232();
	virtual void Function233();
	virtual void Function234();
	virtual void Function235();
public:
	virtual void setAuxValue(int);
	virtual void setSize(float, float);
	virtual void onOrphan(void);
	virtual void wobble(void);
	virtual void wasHurt(void);
	virtual void startSpinAttack(void);
	virtual void stopSpinAttack(void);
	virtual void setDamageNearbyMobs(bool);
private:
	virtual void Function244();
public:
	virtual void reloadLootTable(void);
private:
	virtual void Function246();
public:
	virtual int getDeletionDelayTimeSeconds(void);
	virtual void kill(void);
private:
	virtual void Function249();
public:
	virtual void shouldDropDeathLoot(void);
private:
	virtual void Function251();
	virtual void Function252();
	virtual void Function253();
public:
	virtual float getNextStep(float);
	virtual int getLootTable(void);
private:
	virtual void Function256();
	virtual void Function257();
public:
	virtual void shouldTryMakeStepSound(void);
	virtual void canMakeStepSound(void);
private:
	virtual void Function260();
public:
	virtual void markHurt(void);
private:
	virtual void Function262();
	virtual void Function263();
	virtual void Function264();
	virtual void Function265();
	virtual void Function266();
public:
	virtual void _makeFlySound(void);
private:
	virtual void Function268();
	virtual void Function269();
public:
	virtual void updateWaterState(void);
	virtual void doWaterSplashEffect(void);
	virtual void spawnTrailBubbles(void);
private:
	virtual void Function273();
public:
	virtual void _removePassenger(uint64_t const&, bool, bool, bool);
	virtual void _onSizeUpdated(void);
	virtual void _doAutoAttackOnTouch(Actor&);
	virtual void knockback(Actor*, int, float, float, float, float, float);
	virtual void spawnAnim(void);
	virtual void setSprinting(bool);
	virtual int getHurtSound(void);
	virtual int getDeathSound(void);
private:
	virtual void Function282();
public:
	virtual int getSpeed(void);
	virtual void setSpeed(float);
	virtual int getJumpPower(void);
private:
	virtual void Function286();
public:
	virtual int getMeleeWeaponDamageBonus(Actor);
	virtual int getMeleeKnockbackBonus(void);
	virtual void travel(float, float, float);
private:
	virtual void Function290();
public:
	virtual void applyFinalFriction(float, bool);
	virtual void updateWalkAnim(void);
	virtual void aiStep(void);
private:
	virtual void Function294();
public:
	virtual void pushActors(void);
	virtual void lookAt(Actor*, float, float);
	virtual bool isLookingAtAnEntity(void);
	virtual void checkSpawnRules(bool);
	virtual void checkSpawnObstruction(void);
	virtual float getAttackAnim(float);
private:
	virtual void Function301();
	virtual void Function302();
	virtual void Function303();
	virtual void Function304();
public:
	virtual int getTimeAlongSwing(void);
	virtual void ate(void);
	virtual int getMaxHeadXRot(void);
	virtual bool isAlliedTo(Actor);
private:
	virtual void doHurtTarget(Actor*, class ActorDamageCause const&);
public:
	virtual void canBeControlledByPassenger(void);
	virtual void leaveCaravan(void);
	virtual void joinCaravan(Actor);
	virtual void hasCaravanTail(void);
	virtual int getCaravanHead(void);
	virtual int getArmorValue(void);
	virtual int getArmorCoverPercentage(void);
private:
	virtual void Function317();
	virtual void Function318();
	virtual void Function319();
	virtual void Function320();
public:
	virtual void containerChanged(int);
	virtual void updateEquipment(void);
	virtual void clearEquipment(void);
	virtual int getAllArmor(void);
	virtual int getAllArmorID(void);
	virtual int getAllHand(void);
	virtual int getAllEquipment(void);
	virtual int getArmorTypeHash(void);
private:
	virtual void Function329();
public:
	virtual void dropEquipmentOnDeath(void);
private:
	virtual void Function331();
public:
	virtual void sendInventory(bool);
private:
	virtual void Function333();
public:
	virtual void createAIGoals(void);
	virtual void onBorn(Actor&, Actor&);
private:
	virtual void Function336();
public:
	virtual void setTransitioningSitting(bool);
	virtual void attackAnimation(Actor*, float);
	virtual int getAttackTime(void);
private:
	virtual void Function340();
public:
	virtual void canExistWhenDisallowMob(void);
	virtual void useNewAi(void);
	virtual void ascendLadder(void);
private:
	virtual void Function344();
	virtual void Function345();
public:
	virtual void dropContainer(void);
	virtual void initBodyControl(void);
	virtual void jumpFromGround(void);
private:
	virtual void Function349();
public:
	virtual void updateAi(void);
	virtual void newServerAiStep(void);
	virtual void _serverAiMobStep(void);
private:
	virtual void Function353();
	virtual void Function354();
public:
	virtual void dropBags(void);
	virtual void tickDeath(void);
	virtual void updateGliding(void);
	virtual void _allowAscendingScaffolding(void);

private: // Variables
	char pad_0x0000[0x138]; //0x0000
public:
	Vector2 CameraRots; //0x0138
	Vector2 CameraRots2; //0x0140
private:
	char pad_0x0148[0x10]; //0x0148
public:
	Vector3 EyeHeight; //0x0158
private:
	char pad_0x0164[0x70]; //0x0164
public: // 0x1BC
	float fallDistance; //0x01D4
	unsigned char onGround; //0x01D8
	unsigned char onGround2; //0x01D9
	unsigned char WalkingIntoBlock;
	unsigned char onGround3; //0x01DB
	unsigned char WalkingIntoBlock2; //0x01DC
private:
	char pad_0x01DD[0x5B]; //0x01DD
public:
	float StepHeight; //0x0238
private:
	char pad_0x023C[0x4]; //0x023C
public:
	float WalkDistance; //0x0240
	float WalkDistance1; //0x0244
	float MoveDistance; //0x0248
private:
	char pad_0x024C[0xC]; //0x024C
public:
	float MoveDistanceExact; //0x0258
private:
	char pad_0x025C[0x1]; //0x025C
public:
	unsigned char IsInWater; //0x025D
private:
	char pad_0x025E[0x4A]; //0x025E
public:
	__int32 TicksPast; //0x02A8
private:
	char pad_0x02AC[0x1D]; //0x02AC
public:
	unsigned char IsInLava; //0x02C9
private:
	char pad_0x02CA[0x7A]; //0x02CA
public:
	float SpeedCalc; //0x0344
	__int32 SpeedCalc2; //0x0348
	float MoveTick; //0x034C
private:
	char pad_0x0350[0x10]; //0x0350
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
private:
	char pad_0x1E6D[0x393]; //0x1E6D
public:
	Vector2 NetherPortalAnimation; //0x2200
private:
	char pad_0x2208[0x2C]; //0x2208
public:
	Vector3i Position2; //0x2200
	//__int32 PosX; //0x2234
	//__int32 PosY; //0x2238
	//__int32 PosZ; //0x223C
private:
	char pad_0x2240[0x40]; //0x2240
public:
	float IsMoving; //0x2280
private:
	char pad_0x2284[0x2]; //0x2284
public:
	unsigned char IsInPortal; //0x2286
private:
	char pad_0x2287[0xE3]; //0x2287
public:
	unsigned char HeldItemAmount; //0x236A
private:
	char pad_0x236B[0x6D]; //0x236B
public:
	unsigned char SelectedHotbarID; //0x23D8
private:
	char pad_0x23D9[0x37]; //0x23D9
public:
	Vector2 SetRotations; //0x2410
	Vector2 SetRotations2; //0x2418

	bool* _onGround() {
		return reinterpret_cast<bool*>((uintptr_t)(this) + 0x1D8);
	};

	float* SwingAnimation() {
		return reinterpret_cast<float*>((uintptr_t)(this) + 0x7C8);
	};

	AABB* _position() {
		return reinterpret_cast<AABB*>((uintptr_t)(this) + 0x4C0);
	};

	Vector3* _velocity() {
		return reinterpret_cast<Vector3*>((uintptr_t)(this) + 0x4F8);
	};

public: // Functions
	void SetRenderPosition(Vector3 v) {
		Camera.lower = v;
		Camera.upper = v;
	};

	void SetPos(Vector3 v) {
		this->Position.lower.x = v.x;
		this->Position.lower.y = v.y;
		this->Position.lower.z = v.z;

		this->Position.upper.x = v.x + 0.6f;
		this->Position.upper.y = v.y + 1.8f;
		this->Position.upper.z = v.z + 0.6f;
	};

	void PortalAnimation() {
		this->NetherPortalAnimation = Vector2(1, 1);
	};

	void ClearPortalAnimation() {
		this->NetherPortalAnimation = Vector2(0, 0);
	};

	void SetFieldOfView(float v) {
		//*(float*)((uintptr_t)(this) + 0x10F0) = v;
		*(float*)((uintptr_t)(this) + 0x1058) = v;
		//*(float*)((uintptr_t)(this) + 0x1140) = v;
	};

	float FieldOfView() {
		return *reinterpret_cast<float*>(this + 0x1058);
	};

	void FixReadExcp() { // VirtualUnlock
		VirtualUnlock(this, 0x2418);
	};

	Vector2* bodyRots() {
		return reinterpret_cast<Vector2*>((uintptr_t)(this) + 0x138);
	};
};
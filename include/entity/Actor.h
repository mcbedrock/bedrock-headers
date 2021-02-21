#pragma once

#include "world/level/Level.h"
#include "world/BlockSource.h"
#include "math/Vec3.h"
#include "math/BlockPos.h"
#include "math/Vec2.h"
#include "util/ActorRuntimeID.h"
#include <string>
#include <regex>
#include "effect/MobEffect.h"
#include "effect/MobEffectInstance.h"
#include "GameMode.h"
#include "util/ActorType.h"

struct ActorDamageSource;
struct BlockSource;
struct ActorDefinitionGroup;
struct ActorDefinitionIdentifier;
struct Mob;
enum struct ArmorSlot;

struct Actor {
	// I added virtual functions but the way libminecraftpe.so links broke stuff
	//uintptr_t** vtable;
	// ReClass.NET is used for helping find these and generating what you see
	// Some of the higher values do NOT apply to all Actors, inheritance is a bitch
	char pad_0000[228]; //0x0000
	int32_t dimensionId; //0x00E4
	char pad_00E8[48]; //0x00E8
	Vec2 rotation; //0x0118
	Vec2 prevRotation; //0x0120
	float diveProgress; //0x0128
	float prevDiveProgress; //0x012C
	char pad_0130[8]; //0x0130
	float x; //0x0138
	float y; //0x013C
	float z; //0x0140
	char pad_0144[112]; //0x0144
	float fallDistance; //0x01B4
	bool onGround; //0x01B8
	bool prevOnGround; //0x01B9
	bool collidedHorizontally; //0x01BA
	bool collidedVertically; //0x01BB
	bool collided; //0x01BC
	char pad_01BD[91]; //0x01BD
	float stepHeight; //0x0218
	char pad_021C[112]; //0x021C
	uint32_t ticksExisted; //0x028C
	uint32_t hurtTime; //0x0290
	char pad_0294[24]; //0x0294
	bool isOnMagma; //0x02AC
	bool isOnFire; //0x02AD
	char pad_02AE[426]; //0x02AE
	union {
		AABB aabb;
		struct {
			Vec3 minBB; //0x0458
			Vec3 maxBB; //0x0464
		};
	};
	char pad_0470[4]; //0x0470
	float width; //0x0474
	float height; //0x0478
	Vec3 pos; //0x047C
	Vec3 prevPos; //0x0488
	Vec3 motion; //0x0494
	//char pad_04A0[3188]; //0x04A0
	//class GameMode *gameMode; //0x1114
	// Yikers, see bottom for details...
	class GameMode *getGameMode() {
		return reinterpret_cast<GameMode *>((*reinterpret_cast<uintptr_t *>(reinterpret_cast<uintptr_t>(this) + 0x1114)) >> 32);
	}

	Actor(ActorDefinitionGroup *, ActorDefinitionIdentifier const &);
	Actor(BlockSource &, std::string const &);
	Actor(Level &);

	void doFireHurt(int);
	void normalTick();
	void burn(int, bool);
	void feed(int);
	void hurt(ActorDamageSource const &, int, bool, bool);
	void die(ActorDamageSource const&);
	void setCharged(bool);
	void setDancing(bool);
	void setNameTag(std::string const &);
	void setPowered(bool);
	void setResting(bool);
	void setSitting(bool);
	void setSwimmer(bool);
	void setTempted(bool);
	void setVariant(int);
	void setRiding(bool, bool);
	void setCanClimb(bool);
	void setClimbing(bool);
	void setHurtTime(int);
	void setStanding(bool);
	void setStrength(int);
	void startRiding(Actor &);
	void serializationSetHealth(int);
	bool isRiding() const;
	void setEnchanted(bool);
	void setCanPowerJump(bool);
	void setExperimental(bool);
	void setCanFly(bool);
	void setOnFire(int);
	void setMoving(bool);
	void setInLove(Actor *);
	void setSaddle(bool);
	void setTarget(Actor *);
	void stopSwimming();
	void startSwimming();
	void teleportTo(Vec3 const &, bool, int, int);
	void animateHurt();
	void moveRelative(float, float, float, float);
	void move(Vec3 const&);
	void onTame();
	void onMate(Mob &);
	void despawn();
	bool isInsidePortal();
	bool canShowNameTag();
	bool isSwimming() const;
	bool isSneaking() const;
	bool isFishable() const;
	bool isClimbing() const;
	bool isInClouds() const;
	bool isInWater() const;
	bool isImmersedInWater() const;
	ItemStack &getArmor(ArmorSlot) const;
	std::vector<ItemInstance> getSlotItems();
	ActorRuntimeID getRuntimeID() const;
	ActorUniqueID const &getUniqueID() const;
	void setSize(float width, float height);
	void attack(Actor &);
	int getHealth() const;
	void swing();
	const Vec3 &getPosExtrapolated(float) const;
	const Vec3 &getPos() const;
	const Vec3 &getInterpolatedPosition(float) const;
	const Vec3 &getPosOld() const;
	const Vec3 &getViewVector(float) const;
	Level &getLevel() const;
	const std::string &getNameTag() const;
	std::vector<Actor> fetchNearbyActorsSorted(const Vec3 &pos, ActorType);
	const std::string getUnformattedNameTag() const {
		static const std::regex colorCodes{"\u00A7[0-9A-Fa-fK-Ok-oRr]"};
		return std::regex_replace(getNameTag(), colorCodes, "");
	}
	bool hasTags() const;
	float distanceTo(Actor const &) const;
	float distanceTo(Vec3 const &) const;
	void addEffect(MobEffectInstance const &);
	void onEffectAdded(MobEffectInstance &);
	void removeAllEffects();
	void removeEffect(int);
	BlockPos getBlockTarget() const;
	void setRot(Vec2 const &);
	Vec2 getRotation() const;
	BlockSource &getRegion() const;
	void buildForward() const;
	void setPos(Vec3 const &);
	bool isInvisible() const;
	bool isRemoved() const;
	bool isAlive() const;
	void setInvisible(bool);
	bool hasEffect(MobEffect const&) const;
	const MobEffectInstance *getEffect(MobEffect const&) const;
	signed int checkInsideBlocks(float offset);
	bool isInWall() const;
	bool canSee(Actor const&) const;
	bool canSee(Vec3 const&) const;
	bool isJumping() const;
	bool isTickingEntity() const;
	bool isPickable();
	bool isWalker() const;
	bool isGlobal() const;
	bool isInWorld() const;
	bool isWASDControlled();
	bool isImmobile() const;
	bool isSilent();
	bool isBlocking() const;
	bool isStanding() const;
	bool getAlwaysShowNameTag() const;
	void setNameTagVisible(bool);
	bool isRegionValid() const;
	bool isLayingDown() const;
	int getSkinID() const;
	ActorType getEntityTypeId() const;
	ActorRuntimeID getRideRuntimeID() const;
	Actor &getRide() const;
	bool hasType(ActorType) const;
	bool isOverWater() const;
	void lerpMotion(const Vec3 &);
	bool isMoving() const;
	bool isSleeping() const;
	void baseTick();
	bool isLocalPlayer() const;
	uint32_t getHurtTime() const;
};

static_assert(offsetof(Actor, dimensionId) == 0xE4);
static_assert(offsetof(Actor, motion) == 0x494);
//static_assert(offsetof(Actor, gameMode) == 0x1114);
//char (*_test)[offsetof(Actor, gameMode)] = 1;

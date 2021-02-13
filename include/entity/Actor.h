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

enum struct ArmorSlot {};

struct Actor {
	char pad_0x0000[0x64];
	int dimensionId; // 0x64
	char pad_0x0068[0x14];
	Vec2 unk;
	Vec2 rotation; // 0x84 0x88
	Vec2 prevRotation; // 0x8c 0x90
	float diveProgress; // 0x94
	float prevDiveProgress; // 0x98
	char pad_0x009c[0x8];
	Vec3 realPos; // 0xa4
	char pad_0x00b0[0x40];
	bool onGround; // 0xF0
	bool prevOnGround; // 0xF1
	bool collidedHorizontally; // 0xF2
	bool collidedVertically; // 0xF3
	bool collided; // 0xF4
	char pad_0x00f5[0x7];
	float fallDistance; // 0xFC
	char pad_0x00fd[0x57];
	float stepHeight; // 0x158
	char pad_0x015c[0x64];
	unsigned int ticksExisted; // 0x1c0
	int hurtTime; // 0x1c4
	char pad_0x01c8[0xaa8]; // (large jump)
	AABB aabb; // 0xc70
	char pad_0x0c88[0x4];
	float width; // 0xc8c (0.6)
	float height; // 0xc90 (1.8)
	Vec3 motion; // 0xc94
	Vec3 pos; // 0xca0
	Vec3 prevPos; // 0xcac
	char pad_0xcb8[0x8a0]; // (even larger jump)
	int pad;
	// offset for gamemode increased by 4 bytes in 1.12.1
	GameMode *gameMode; // 0x1558 holy hell

	Actor(ActorDefinitionGroup *, ActorDefinitionIdentifier const &);

	Actor(BlockSource &, std::string const &);

	Actor(Level &);

	void doFireHurt(int);

	void normalTick();

	void restrictTo(BlockPos const &, float);

	void burn(int, bool);

	void feed(int);

	void hurt(ActorDamageSource const &, int, bool, bool);

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

	//bool onLadder(bool vine) const;

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

	void onTame();

	void onMate(Mob &);

	void despawn();

	bool isInsidePortal();

	bool canShowNameTag();

	bool wantsMoreFood();

	bool canBeLeashed();

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

	// Hitboxes
	void setSize(float width, float height);

	void attack(Actor &);

	int getHealth() const;

	void swing();

	const Vec3 &getPosExtrapolated(float) const;

	const Vec3 &getPos() const;

	// We gettin real comfy up in here with them symbols mmmhhm
	const Vec3 &getInterpolatedPosition(float) const;

	const Vec3 &getPosOld() const;

	const Vec3 &getViewVector(float) const;

	Level &getLevel() const;

	const std::string &getNameTag() const;

	//const std::string &getFormattedNameTag() const;
	std::vector<Actor> fetchNearbyActorsSorted(const Vec3 &pos, ActorType);

	const std::string getUnformattedNameTag() const {
		static const std::regex colorCodes{"\u00A7[0-9A-Fa-fK-Ok-oRr]"};
		return std::regex_replace(getNameTag(), colorCodes, "");
	}

	const char *getName() const {
		return getUnformattedNameTag().c_str();
	};

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

	int getHurtTime() const;

	bool isJumping() const;

	bool isTickingEntity() const;

	bool isPickable();

	bool isPushable() const;

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

	//std::vector<Actor> fetchNearbyActorsSorted(const Vec3 &, ActorType);

	ActorType getEntityTypeId() const;

	ActorRuntimeID getRideRuntimeID() const;

	Actor &getRide() const;

	bool hasType(ActorType) const;

	bool isOverWater() const;

	void lerpMotion(const Vec3 &);
};

static_assert(offsetof(Actor, dimensionId) == 0x64);
static_assert(offsetof(Actor, rotation) == 0x84);
static_assert(offsetof(Actor, realPos) == 0xA4);
static_assert(offsetof(Actor, pad_0x00b0) == 0xb0);
static_assert(offsetof(Actor, hurtTime) == 0x1c4);
static_assert(offsetof(Actor, aabb) == 0xc70);
static_assert(offsetof(Actor, width) == 0xc8c);
static_assert(offsetof(Actor, height) == 0xc90);
static_assert(offsetof(Actor, motion) == 0xc94);
static_assert(offsetof(Actor, pos) == 0xca0);
static_assert(offsetof(Actor, prevPos) == 0xcac);
//static_assert(offsetof(Actor, gameMode) == 0x155c);

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
	// ReClass.NET is used for helping find these and generating what you see
	char pad_0000[280]; //0x0000
	Vec2 rotation; //0x0118
	Vec2 prevRotation; //0x0120
	float diveProgress; //0x0128
	float prevDiveProgress; //0x012C
	char pad_0130[8]; //0x0130
	float x; //0x0138
	float y; //0x013C
	float z; //0x0140
	char pad_0144[8]; //0x0144
	// warning this is not actually ticks existed (it appears to have been removed), but it is a ticker that only goes from 0-255
	// only used for compatibility with other tick tests that use modulo on this
	uint8_t ticksExisted; //0x014C
	char pad_014D[103]; //0x014D
	float fallDistance; //0x01B4
	bool b_unk; //0x01B8
	bool collidedVertically; //0x01B9
	bool collidedHorizontally; //0x01BA
	bool onGround; //0x01BB
	bool prevOnGround; //0x01BC
	char pad_01BD[91]; //0x01BD
	float stepHeight; //0x0218
	char pad_021C[116]; //0x021C
	uint32_t hurtTime; //0x0290
	char pad_0294[452]; //0x0294
	AABB aabb; //0x0458
	char pad_0470[4]; //0x0470
	float width; //0x0474
	float height; //0x0478
	Vec3 pos; //0x047C
	Vec3 prevPos; //0x0488
	Vec3 motion; //0x0494
	Vec3 N00000651; //0x04A0
	char pad_04AC[1688]; //0x04AC
	float N000001CF; //0x0B44
	float N00000640; //0x0B48
	float N0000063D; //0x0B4C
	float N000001D0; //0x0B50
	float N00000644; //0x0B54
	float N000001D1; //0x0B58
	char pad_0B5C[2590]; //0x0B5C

	// Old map, from 1.12.x iirc kept shortly for reference when finding values for current ver (1.16.200)
	/*
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
	*/

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

	bool isMoving() const;
};
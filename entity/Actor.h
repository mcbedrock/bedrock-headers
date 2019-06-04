#pragma once

#include "../world/level/Level.h"
#include "../world/BlockSource.h"
#include "../math/Vec3.h"
#include "../math/BlockPos.h"
#include "../math/Vec2.h"
#include "ActorRuntimeID.h"
#include <string>

struct ActorDamageSource;

struct BlockSource;

struct ActorDefinitionGroup;

struct ActorDefinitionIdentifier;

struct Mob;

struct MobEffectInstance;

struct Actor {
	// TODO: find types
	static Actor *RIDING_TAG;
	static Actor *TOTAL_AIR_SUPPLY;
	static Actor *DAMAGE_NEARBY_MOBS_DURATION;

	Actor(ActorDefinitionGroup *, ActorDefinitionIdentifier const &);

	Actor(BlockSource &, std::string const &);

	Actor(Level &);

	~Actor();

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

	void setHurtTime(int);

	void setStanding(bool);

	void setStrength(int);

	void startRiding(Actor &);

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

	ActorRuntimeID getRuntimeID() const;

	ActorUniqueID const &getUniqueID() const;

	// Hitboxes
	void setSize(float width, float height);

	virtual void attack(Actor &);

	int getHealth() const;

	void swing();

	Vec3 const &getPos() const;

	Level &getLevel();

	const std::string &getNameTag() const;

	const char *getName() { return getNameTag().c_str(); };

	float distanceTo(Actor const &) const;

	float distanceTo(Vec3 const &) const;

	void addEffect(MobEffectInstance const &);

	void onEffectAdded(MobEffectInstance &);

	void removeAllEffects();

	void removeEffect(int);

	BlockPos getBlockTarget() const;

	void setRot(Vec2 const&);

	Vec2 getRotation() const;

	BlockSource &getRegion() const;

	void buildForward() const;
};

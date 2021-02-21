#pragma once

#include "Actor.h"

struct ActorDamageSource;

struct Sensing;

struct Mob : Actor {
	bool isSprinting() const;
	void die(ActorDamageSource const &);
	void jumpFromGround();
	void setSpeedModifier(float);
	void setSpeed(float);
	void setSprinting(bool); // doesn't like to work virtually togglesprint pls
	void animateHurt();
	void setSneaking(bool);
	bool isGliding() const;
	void updateGliding();
	bool isAlive() const;
	bool frostWalk();
	int getGlidingTicks() const;
	int getTimeAlongSwing();
	bool isSleeping() const;
	void swing();
	void attack(Actor &);
	void baseTick();
	bool isJumping() const;
	void doFireHurt(int);
	void normalTick();
};

#pragma once

#include "Actor.h"

struct ActorDamageSource;

struct Sensing;

struct Mob : Actor {
	bool isSprinting() const;

	void die(ActorDamageSource const &);

	void jumpFromGround();

	void setSpeedModifier(float);

	void setSprinting(bool);

	void animateHurt();

	void setSneaking(bool);

	bool isGliding() const;

	int getGlidingTicks() const;

	Sensing& getSensing();

	bool isSleeping() const;
};

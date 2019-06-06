#pragma once

#include "Actor.h"

struct ActorDamageSource;

struct Mob : Actor {
	void die(ActorDamageSource const &);

	void jumpFromGround();

	void setSpeedModifier(float);

	//void setSpeed(float);

	void setSprinting(bool);

	void animateHurt();

	void setSneaking(bool);
};

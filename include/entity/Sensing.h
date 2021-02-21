#pragma once

#include "Actor.h"
#include "Mob.h"
#include "math/Vec3.h"

struct Sensing {
	bool canSee(Actor const&);

	bool withinFOV(Mob&, Vec3 const&, float);
};
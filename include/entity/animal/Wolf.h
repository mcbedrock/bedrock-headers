#pragma once

#include "../Mob.h"

struct Actor;

struct Wolf : Mob {
	void onBorn(Mob &, Mob &);

	void setInterested(bool);

	void setSitting(bool);

	void setWet(bool);

	void addRider(Actor &);

	bool isAlliedTo(Mob *);

	bool isInterested() const;

	bool isWet() const;
};

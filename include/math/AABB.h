#pragma once

#include "Vec3.h"

struct AABB {
	Vec3 min, max;

	AABB();

	AABB(float, float, float, float, float, float);

	AABB(Vec3 const&, Vec3 const&);

	// Check if these two return vals are right, guessed off BDS
	AABB set(AABB const&);

	AABB &set(Vec3 const&, Vec3 const&);

	void set(float, float, float, float, float, float);

	void expand(Vec3 const&);

	float getSize() const;

	float getVolume() const;

	Vec3 getBounds() const;

	Vec3 getCenter() const;

	AABB grow(Vec3 const&) const;

	AABB resize(Vec3 const&) const;

	AABB shrink(Vec3 const&) const;

	//HitResult clip(Vec3 const&, Vec3 const&) const;

	AABB translated(Vec3 const&) const;

	// TODO: Cause grow and expand doesn't do what I want them to or I just didn't write their signatures correctly >.<

	void offset(const Vec3 &o) {
		min.x += o.x;
		min.y += o.y;
		min.z += o.z;

		max.x += o.x;
		max.y += o.y;
		max.z += o.z;
	}

	void offset(float x, float y, float z) {
		min.x += x;
		min.y += y;
		min.z += z;

		max.x += x;
		max.y += y;
		max.z += z;
	}

	static const AABB ZERO;
};
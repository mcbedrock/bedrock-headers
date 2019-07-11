#pragma once

struct AABB {
	float f1, f2, f3, f4, f5, f6;

	AABB();

	AABB(float, float, float, float, float, float);

	AABB(Vec3 const&, Vec3 const&);

	void set(Vec3 const&, Vec3 const&);

	void expand(Vec3 const&);

	float getSize() const;

	float getVolume() const;

	Vec3 getBounds() const;

	Vec3 getCenter() const;

	static const AABB ZERO;
};
#pragma once

#include "Vec3.h"

struct Vec2 {
	float pitch, yaw;

	Vec2(float pitch, float yaw) : pitch(pitch), yaw(yaw) {}

	static Vec3 NEG_UNIT_X,
				NEG_UNIT_Y,
				MAX,
				MIN,
				ONE,
				ZERO,
				UNIT_X,
				UNIT_Y;
};
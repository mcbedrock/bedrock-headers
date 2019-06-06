#pragma once

struct Vec2 {
	float pitch, yaw;

	Vec2(float x, float y) : pitch(x), yaw(y) {}

	static Vec3 NEG_UNIT_X,
				NEG_UNIT_Y,
				MAX,
				MIN,
				ONE,
				ZERO,
				UNIT_X,
				UNIT_Y;
};
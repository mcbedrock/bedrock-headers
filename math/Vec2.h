#pragma once

struct Vec2 {
	float pitch, yaw;
	// x = pitch
	// y = yaw

	Vec2(float x, float y) : pitch(x), yaw(y) {}
};
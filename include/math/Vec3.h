#pragma once

struct BlockPos;

struct Vec3 {
	float x, y, z;

	Vec3(BlockPos const &);

	Vec3(float x, float y, float z) : x(x), y(y), z(z) {};

	Vec3(float x) : x(x), y(x), z(x) {};

	Vec3() : x(0.0), y(0.0), z(0.0) {};

	static Vec3	NEG_UNIT_X,
				NEG_UNIT_Y,
				NEG_UNIT_Z,
				MAX,
				MIN,
				ONE,
				TWO,
				HALF,
				ZERO,
				UNIT_X,
				UNIT_Y,
				UNIT_Z;
};
#pragma once

struct BlockPos;

struct Vec3 {
	float x, y, z;

	Vec3(BlockPos const &);

	Vec3(float x, float y, float z) : x(x), y(y), z(z) {};

	Vec3(float x) : x(x), y(x), z(x) {};

	Vec3() : x(0.0), y(0.0), z(0.0) {};
};
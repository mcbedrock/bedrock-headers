#pragma once

#include <sstream>

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

	bool operator==(Vec3 &vec3) {
		return x == vec3.x && y == vec3.y && z == vec3.z;
	}

	bool operator!=(Vec3 &vec3) {
		return x != vec3.x || y != vec3.y || z != vec3.z;
	}

	Vec3 add(const Vec3 &o) const {
		return Vec3(x + o.x, y + o.y, z + o.z);
	}

	Vec3 add(float ox, float oy, float oz) const {
		return Vec3(x + ox, y + oy, z + oz);
	}

	Vec3 subtract(const Vec3 &o) const {
		return Vec3(x - o.x, y - o.y, z - o.z);
	}

	Vec3 subtract(float ox, float oy, float oz) const {
		return Vec3(x - ox, y - oy, z - oz);
	}
};
#pragma once

#include <sstream>
#include "Vec2.h"

struct BlockPos;

struct Vec3 {
	union {
		struct {
			float x, y, z;
		};
		struct {
			float pitch, headYaw, yaw;
		};
	};

	Vec3(BlockPos const &);

	Vec3(float x, float y, float z) : x(x), y(y), z(z) {};

	Vec3(float x) : x(x), y(x), z(x) {};

	Vec3() : x(0.0), y(0.0), z(0.0) {};

	// pitch, headyaw, yaw for Vec3 rotations
	// conversion from vec2 we just combine yaw because most server software doesn't even impl it
	explicit Vec3(const Vec2 &rotations) : x(rotations.x), y(rotations.y), z(rotations.y) {};

	explicit Vec3(uint8_t xRot, uint8_t yRot, uint8_t zRot) : pitch(xRot * (360 / 256)), headYaw(yRot * (360 / 256)), yaw(zRot * (360 / 256)) {}

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

	Vec3 &operator=(const Vec3 &vec3) {
		x = vec3.x;
		y = vec3.y;
		z = vec3.z;
		return *this;
	}

	Vec3 add(const Vec3 &o) const {
		return {x + o.x, y + o.y, z + o.z};
	}

	Vec3 add(float ox, float oy, float oz) const {
		return {x + ox, y + oy, z + oz};
	}

	Vec3 subtract(const Vec3 &o) const {
		return {x - o.x, y - o.y, z - o.z};
	}

	Vec3 subtract(float ox, float oy, float oz) const {
		return {x - ox, y - oy, z - oz};
	}

	Vec3 multiply(const Vec3 &o) const {
		return {x * o.x, y * o.y, z * o.z};
	}

	Vec3 multiply(float ox, float oy, float oz) const {
		return {x * ox, y * oy, z * oz};
	}

	Vec3 multiply(float h, float v) const {
		return {x * h, y * v, z * h};
	}

	friend std::ostream& operator<<(std::ostream &ss, const Vec3 &vec3) {
		return ss << "Vec3{" << vec3.x << ", " << vec3.y << ", " << vec3.z <<  "}";
	}

	float delta() {
		return std::sqrt(x * x + z * z);
	}

	float distance(const Vec3 &o) const {
		return std::abs(x - o.x) + std::abs(y - o.y) + std::abs(z - o.z);
	}
};
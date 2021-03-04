#pragma once

#include <sstream>
#include "Vec2.h"

struct BlockPos;

// TODO: Cleanup self defined utility functions (constexpr stuff?)
struct Vec3 {
	union {
		struct {
			float x, y, z;
		};
		struct {
			float pitch, yaw, headYaw;
		};
	};

	Vec3(BlockPos const &);

	// Pos is unknown
	//Vec3(Post const &);

	Vec3(float x, float y, float z) : x(x), y(y), z(z) {};

	Vec3(float x) : x(x), y(x), z(x) {};

	Vec3() : x(0.f), y(0.f), z(0.f) {};

	// Conversion from Vec2 we just combine yaw (not like most server softwares impl it anyway)
	explicit Vec3(const Vec2 &rotations) : x(rotations.x), y(rotations.y), z(rotations.y) {};
	// Conversion for the lossy bytes some packets use for rotations
	explicit Vec3(uint8_t xRot, uint8_t yRot, uint8_t zRot) : pitch(xRot * (360.f / 256.f)), yaw(yRot * (360.f / 256.f)), headYaw(zRot * (360.f / 256.f)) {};

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

	inline bool operator==(Vec3 &vec3) {
		return x == vec3.x && y == vec3.y && z == vec3.z;
	}

	inline bool operator!=(Vec3 &vec3) {
		return x != vec3.x || y != vec3.y || z != vec3.z;
	}

	inline Vec3 &operator=(const Vec3 &vec3) {
		x = vec3.x;
		y = vec3.y;
		z = vec3.z;
		return *this;
	}

	inline Vec3 add(const Vec3 &o) const {
		return {x + o.x, y + o.y, z + o.z};
	}

	inline Vec3 add(float ox, float oy, float oz) const {
		return {x + ox, y + oy, z + oz};
	}

	inline Vec3 subtract(const Vec3 &o) const {
		return {x - o.x, y - o.y, z - o.z};
	}

	inline Vec3 subtract(float ox, float oy, float oz) const {
		return {x - ox, y - oy, z - oz};
	}

	inline Vec3 multiply(const Vec3 &o) const {
		return {x * o.x, y * o.y, z * o.z};
	}

	inline Vec3 multiply(float ox, float oy, float oz) const {
		return {x * ox, y * oy, z * oz};
	}

	inline Vec3 multiply(float h, float v) const {
		return {x * h, y * v, z * h};
	}

	inline friend std::ostream& operator<<(std::ostream &ss, const Vec3 &vec3) {
		return ss << "Vec3{" << vec3.x << ", " << vec3.y << ", " << vec3.z <<  "}";
	}

	inline float delta() {
		return std::sqrt(x * x + z * z);
	}

	inline float distance(const Vec3 &o) const {
		return std::abs(x - o.x) + std::abs(y - o.y) + std::abs(z - o.z);
	}
};
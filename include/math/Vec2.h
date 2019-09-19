#pragma once

#include "Facing.h"

#include <cmath>
#include <ostream>

struct Vec2 {
	union {
		struct {
			float pitch, yaw;
		};
		struct {
			float x, y;
		};
	};

	Vec2(float x, float y) : x(x), y(y) {}

	static Vec2 NEG_UNIT_X,
				NEG_UNIT_Y,
				MAX,
				MIN,
				ONE,
				ZERO,
				UNIT_X,
				UNIT_Y;

	/*operator Facing::LookDirection::LookDirection() {
		return static_cast<Facing::LookDirection::LookDirection>(Direction::getDirection(sin(yaw) * 0.0174532, cos(yaw) * 0.0174532));
	}*/

	/*Vec2 &operator =(const Vec2 &o) {
		x = o.x;
		y = o.y;
		return *this;
	}*/

	Vec2 distance(const Vec2 &o) {
		return {std::abs(x - o.x), std::abs(y - o.y)};
	}

	Vec2 add(const Vec2 &o) {
		return {x + o.x, y + o.y};
	}

	Vec2 subtract(const Vec2 &o) const {
		return {x - o.x, y - o.y};
	}

	Vec2 multiply(const Vec2 &o) const {
		return {x * o.x, y * o.y};
	}

	Vec2 limit(const Vec2 &o) const {
		return {
				x > o.x ? o.x : x < o.x ? -o.x : x,
				y > o.y ? o.y : y < o.y ? -o.y : y
		};
	}

	friend std::ostream& operator<<(std::ostream &ss, const Vec2 &vec2) {
		return ss << "Vec2{" << vec2.pitch << ", " << vec2.yaw <<  "}";
	}
};
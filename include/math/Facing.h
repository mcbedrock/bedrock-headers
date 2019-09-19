#pragma once

#include <unordered_map>

struct Direction {
	static unsigned char getDirection(float, float);
};

namespace Facing {
	namespace Direction {
		enum Direction : unsigned char {
			DOWN, UP, NORTH, SOUTH, WEST, EAST, INVALID = 255
		};
		static std::unordered_map<unsigned char, const char *> names{
				{ DOWN, "Below" },
				{ UP, "Above" },
				{ NORTH, "North" },
				{ SOUTH, "South" },
				{ WEST, "West" },
				{ EAST, "East" },
				{ INVALID, "" }
		};
	};
	namespace LookDirection {
		enum LookDirection : unsigned char {
			SOUTH, WEST, NORTH, EAST
		};
		static Direction::Direction toDirection(LookDirection lookDirection) {
			switch (lookDirection) {
				case SOUTH:
					return Direction::SOUTH;
				case WEST:
					return Direction::WEST;
				case NORTH:
					return Direction::NORTH;
				case EAST:
					return Direction::EAST;
			}
		};
	};
};
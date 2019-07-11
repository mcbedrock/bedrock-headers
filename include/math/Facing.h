#pragma once

namespace Facing {
	namespace Direction {
		enum Direction : unsigned char {
			DOWN, UP, NORTH, SOUTH, WEST, EAST, INVALID = 255
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
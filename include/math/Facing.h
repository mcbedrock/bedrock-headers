#pragma once

#include <unordered_map>

// Yes, Player->getDirection() is weird so this was required
enum struct LookDirection : unsigned char {
	SOUTH, WEST, NORTH, EAST
};

struct Direction {
	enum : unsigned char {
		DOWN, UP, NORTH, SOUTH, WEST, EAST, INVALID = 255
	};

	static unsigned char getDirection(float, float);
	static unsigned char getDirection(int, int, int, int);

	// If it's INVALID you're on your own, I don't see the point in allocating 255 pointers
	static constexpr const char *names[] = {"Below", "Above", "North", "South", "West", "East"};

	static unsigned char convertFacingDirectionToDirection(unsigned char);
	// Did I reimpl convertFacingDirectionToDirection?
	/*static constexpr unsigned char fromLook(LookDirection look) {
		switch (look) {
			case LookDirection::SOUTH:
				return SOUTH;
			case LookDirection::WEST:
				return WEST;
			case LookDirection::NORTH:
				return NORTH;
			case LookDirection::EAST:
				return EAST;
		}
		return INVALID;
	}*/
};

// TODO: Real Facing struct, though it's very rarely used (eg. BlockGeometry and BlockTessellator)
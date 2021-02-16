#pragma once

struct MoveInputHandler {
	// unknown bools are afaik duplicates
	char pad_0000[8]; //0x0000
	float strafe; //0x0008
	float forward; //0x000C
	char pad_0010[56]; //0x0010
	bool N000008EF; //0x0048
	bool N000008FE; //0x0049
	char pad_004A[1]; //0x004A
	bool jump; //0x004B
	bool sneak; //0x004C
	char pad_004D[2]; //0x004D
	bool N000008FF; //0x004F
	// there's a couple bools that change in this padding
	char pad_0050[11]; //0x0050
	// these can show two opposite directions being pressed at once while strafe and forward cancel out and become 0
	bool up; //0x005B
	bool down; //0x005C
	bool left; //0x005D
	bool right; //0x005E

	/**
	 * Checks if player is moving forward (or strafing forward)
	 * @return bool
	 */
	bool isMovingForward() const;

	/**
	 * I recall this not working, see for yourself
	 * @return bool
	 */
	bool isPlayerMoving() const;
};
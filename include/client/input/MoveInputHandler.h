#pragma once

struct MoveInputHandler {
	char pad_0000[4];
	float strafe, forward; // 0x4 0x8
	char pad_000c[56];
	bool sneak; // 0x44
	char pad_0045;
	bool jump; // 0x46
	bool sneak2; // 0x47
	char pad_0048[2];
	bool jump2; // 0x4a

	/**
	 * Checks if player is moving forward (or strafing forward)
	 * @return bool
	 */
	bool isMovingForward() const;
};
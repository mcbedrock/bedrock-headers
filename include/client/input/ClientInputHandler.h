#pragma once

#include "MoveInputHandler.h"

struct ClientInputHandler : MoveInputHandler {
	/**
	 * Checks if player is sneaking
	 * @return bool
	 */
	bool isSneaking() const;

	/**
	 * Checks if player is moving forward (or strafing forward)
	 * @return bool
	 */
	bool isMovingForward() const;

	// string?
	void *getCurrentInputMapping() const;
};
#pragma once

#include "InputHandler.h"

struct MoveInputHandler : InputHandler {
	/*
	 * 	bVar1 = true;
 			if ((((*(char *)(iParm1 + 0x62) == '\0') && (*(char *)(iParm1 + 99) == '\0')) &&
      			(*(char *)(iParm1 + 100) == '\0')) &&
     			((*(char *)(iParm1 + 0x65) == '\0' && (*(float *)(iParm1 + 4) == 0.00000000)))) {
    				bVar1 = *(float *)(iParm1 + 8) != 0.00000000;
		return bVar1;
	 */
	bool isPlayerMoving() const; // This always returns true?

	/**
	 * Checks if player is moving forward (or strafing forward)
	 * @return bool
	 */
	bool isMovingForward() const;

	/**
	 * Virtually set sneak key state
	 */
	void setSneakDown(bool);
};
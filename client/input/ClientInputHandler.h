#pragma once

#include "MoveInputHandler.h"

struct ClientInputHandler : MoveInputHandler {
	bool isSneaking() const;

	bool isMovingForward() const;

	// string?
	void *getCurrentInputMapping() const;

};
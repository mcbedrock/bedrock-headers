#pragma once

struct InputHandler {
	int *getStateOrNull(int) const;

	bool areButtonsDown(int);
};
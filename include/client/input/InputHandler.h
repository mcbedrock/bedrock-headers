#pragma once

struct InputHandler {
	/**
	 * Check state of binding
	 * @param key Binding key code
	 * @return int*
	 */
	int *getStateOrNull(int key) const;

	/**
	 * Check if buttons are pressed on a specific controller
	 * @param controller Controller ID to check
	 * @see ClientInstance::getControllerId()
	 * @return bool
	 */
	bool areButtonsDown(int controller);
};
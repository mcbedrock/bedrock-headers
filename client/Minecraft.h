#pragma once

#include "../network/NetworkHandler.h"

struct Minecraft {
	/**
	 * Checks if game is fully initialized
	 * @return bool
	 */
	bool isInitialized() const;

	/**
	 * Get NetworkHandler
	 * @return NetworkHandler
	 */
	NetworkHandler *getNetworkHandler() const;

	/**
	 * Send quitting packet to connected server
	 * @param showDisconnect Whether or not to display the disconnection screen
	 */
	void startLeaveGame(bool showDisconnect);
};

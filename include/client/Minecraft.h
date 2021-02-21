#pragma once

#include "network/NetworkHandler.h"
#include "Timer.h"

struct Minecraft {
	char pad_0000[0x58];
	Timer *gameTimer, *renderTimer;

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

	/**
	 * Get game timer
	 */
	 Timer *getTimer();

	 // Unknown return, probably void
	 void init();
};

#pragma once

#include "network/NetworkHandler.h"
#include "Timer.h"

struct Minecraft {
	char pad_0000[0xA0];
	Level *level;
	Timer *gameTimer, *renderTimer;
	NetworkHandler *networkHandler;

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

	 /**
	  * Called near the mid-end of the title screen
	  */
	 void init();
};

static_assert(offsetof(Minecraft, level) == 0xA0);
static_assert(offsetof(Minecraft, gameTimer) == 0xA8);
static_assert(offsetof(Minecraft, networkHandler) == 0xB8);
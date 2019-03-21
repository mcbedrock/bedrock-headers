#pragma once

#include "../network/NetworkHandler.h"

struct Minecraft {
	NetworkHandler *getNetworkHandler() const;

	void startLeaveGame(bool);
};

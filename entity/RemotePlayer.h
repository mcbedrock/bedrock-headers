#pragma once

#include "Player.h"
#include "../client/PlayerEventCoordinator.h"

struct RemotePlayer : public Player {
	PlayerEventCoordinator *getPlayerEventCoordinator();
};
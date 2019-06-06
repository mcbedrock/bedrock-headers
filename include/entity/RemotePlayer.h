#pragma once

#include "Player.h"
#include "events/PlayerEventCoordinator.h"

struct RemotePlayer : public Player {
	PlayerEventCoordinator *getPlayerEventCoordinator();
};
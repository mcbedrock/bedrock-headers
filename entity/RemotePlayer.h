#pragma once

#include "Player.h"
#include "entity/events/PlayerEventCoordinator.h"

struct RemotePlayer : public Player {
	PlayerEventCoordinator *getPlayerEventCoordinator();
};
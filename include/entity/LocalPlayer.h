#pragma once

#include "Player.h"
#include "events/PlayerEventCoordinator.h"
#include "../client/ClientInstance.h"

struct LocalPlayer : Player {
	PlayerEventCoordinator *getPlayerEventCoordinator();

	ClientPlayerEventCoordinator *_getClientPlayerEventCoordinator();
};


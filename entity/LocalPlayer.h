#pragma once

#include "Player.h"
#include "../client/ClientInstance.h"
#include "entity/events/PlayerEventCoordinator.h"
#include "entity/events/ClientPlayerEventCoordinator.h"

struct LocalPlayer : Player {
	PlayerEventCoordinator *getPlayerEventCoordinator();

	ClientPlayerEventCoordinator *_getClientPlayerEventCoordinator();
};
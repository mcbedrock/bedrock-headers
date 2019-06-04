#pragma once

#include "Player.h"
#include "../client/ClientInstance.h"
#include "entity/events/PlayerEventCoordinator.h"

struct ClientPlayerEventCoordinator {};

struct LocalPlayer : Player {
	PlayerEventCoordinator *getPlayerEventCoordinator();

	ClientPlayerEventCoordinator *_getClientPlayerEventCoordinator();
};


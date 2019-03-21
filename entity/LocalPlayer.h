#pragma once

#include "Player.h"
#include "../client/ClientInstance.h"
#include "../client/PlayerEventCoordinator.h"
#include "../client/ClientPlayerEventCoordinator.h"

struct LocalPlayer : Player {
	PlayerEventCoordinator *getPlayerEventCoordinator();

	ClientPlayerEventCoordinator *_getClientPlayerEventCoordinator();
};
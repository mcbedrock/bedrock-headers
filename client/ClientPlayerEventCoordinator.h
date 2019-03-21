#pragma once

#include "PlayerEventCoordinator.h"

struct ClientPlayerEventCoordinator : PlayerEventCoordinator {
	void sendStartDestroyBlock(Player &player, BlockPos const &block, unsigned char &face);
};
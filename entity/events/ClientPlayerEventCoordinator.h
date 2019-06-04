#pragma once

#include "PlayerEventCoordinator.h"
#include "../LocalPlayer.h"

class IClientInstance {};

class PlayerEventListener {};

class BlockLegacy {};

struct ClientPlayerEventCoordinator : PlayerEventCoordinator {
	void registerClientPlayerEventCoordinatorListener(PlayerEventListener &);

	void unregisterClientPlayerEventCoordinatorListener(PlayerEventListener &);

	void sendPlayerCreated(LocalPlayer &);

	void sendLocalPlayerDeath(IClientInstance &, LocalPlayer &);

	void sendPlayerStopRiding(Player &, bool, bool, bool);

	void sendPlayerStartRiding(Player &, BlockPos const&, BlockLegacy const&);

	void sendStartDestroyBlock(Player &player, BlockPos const &block, unsigned char &face);

	void sendPlayerDestroyedBlock(Player &, BlockLegacy const&);
};
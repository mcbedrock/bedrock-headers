#pragma once

#include "client/EventCoordinator.h"
#include "entity/Player.h"
#include "entity/Actor.h"
#include "item/ItemInstance.h"

struct PlayerEventCoordinator : EventCoordinator {
	void sendPlayerAttackedActor(Player &, Actor &);

	void sendPlayerItemPlaceInteraction(Player &, ItemInstance const &);

	void sendPlayerDestroyedBlock(Player &, int x, int y, int z);
};
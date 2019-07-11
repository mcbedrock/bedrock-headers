#pragma once

#include "Player.h"
#include "events/PlayerEventCoordinator.h"
#include "../client/ClientInstance.h"
#include "../item/Container.h"
#include "../util/GameType.h"

struct InventoryMenu {
	ContainerItemStack *getSlot(int slot) {
		// TODO: Figure out why the original method crashes...
		return const_cast<ContainerItemStack *>(_getContainer()->getSlots()[slot]);
	};
	Container *_getContainer() const;
};

struct LocalPlayer : Player {
	PlayerEventCoordinator *getPlayerEventCoordinator();

	ClientPlayerEventCoordinator *getClientPlayerEventCoordinator();

	InventoryMenu &getInventoryMenu();

	void setPlayerGameTypeWithoutServerNotification(GameType);
};


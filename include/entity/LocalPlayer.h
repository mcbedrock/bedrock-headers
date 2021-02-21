#pragma once

#include "Player.h"
#include "events/PlayerEventCoordinator.h"
#include "client/ClientInstance.h"
#include "item/Container.h"
#include "util/GameType.h"

struct InventoryMenu {
	ContainerItemStack *getSlot(int slot) {
		// TODO: Figure out why the real method doesn't work as expected...
		return const_cast<ContainerItemStack *>(_getContainer()->getSlots()[slot]);
	};

	Container *_getContainer() const;

	void setSlot(int slot, const ContainerItemStack &);
};

struct LocalPlayer : Player {
	PlayerEventCoordinator *getPlayerEventCoordinator();
	ClientPlayerEventCoordinator *getClientPlayerEventCoordinator();
	InventoryMenu &getInventoryMenu();
	void setPlayerGameTypeWithoutServerNotification(GameType);
	void setSelectedItemSlot(short slot) {
		// TODO: Fuck
		getSupplies().selectSlot(slot, getSupplies().getSelectedContainerId());
		getSupplies().setSelectedItem(*getInventoryMenu().getSlot(slot));
	}
	void _applyTurnDelta(const Vec2 &);
	void displayClientMessage(std::string const&);
	void chat(std::string const&);
	void swing();
	void setSprinting(bool);
	void startRiding(Actor &);
	bool isLocalPlayer() const;
	void move(Vec3 const &);
	ClientInstance &getClientInstance() const;
	MoveInputHandler &getMoveInputHandler();
	float getFieldOfViewModifier();
};


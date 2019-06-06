#pragma once

#include "../network/PacketSender.h"
#include "../world/level/Level.h"
#include "gui/GuiData.h"
#include "gui/Font.h"
#include "input/ClientInputHandler.h"
#include "events/ClientInstanceEventCoordinator.h"

struct ClientInstance {
	/**
	 * Checks if a world is currently loaded
	 * @return bool
	 */
	bool isInGame() const;

	/**
	 * Gets PacketSender
	 * @return LoopbackPacketSender
	 */
	PacketSender *getPacketSender();

	/**
	 * Gets InputHandler for LocalPlayer
	 * @return ClientInputHandler
	 */
	ClientInputHandler &getInput() const;

	/**
	 * Gets EventCoordinator for LocalPlayer
	 * @return ClientInstanceEventCoordinator
	 */
	ClientInstanceEventCoordinator *getEventCoordinator();

	/**
	 * Gets primary game font
	 * @return Font
	 */
	Font &getFont() const;

	/**
	 * Gets current Controller ID
	 * @return int
	 */
	int getControllerId() const;
};

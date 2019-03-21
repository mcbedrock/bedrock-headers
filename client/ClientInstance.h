#pragma once

#include "../network/PacketSender.h"
#include "../world/level/Level.h"
#include "gui/GuiData.h"
#include "ClientInputHandler.h"
#include "ClientInstanceEventCoordinator.h"

struct ClientInstance {
	bool isInGame() const;

	PacketSender *getPacketSender();

	ClientInputHandler &getInput() const;

	ClientInstanceEventCoordinator *getEventCoordinator();
};

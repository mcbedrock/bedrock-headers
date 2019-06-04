#pragma once

#include "Packet.h"

/**
 * Packet for Inventory moves and strangely for attacks
 */
struct InventoryTransactionPacket : Packet {
private:
	char filler[1]; // TODO: Find correct offset, been going at this for a while... I finally surrender (for tonight)

public:
	unsigned int i0, entityID, i2, i3;


#include "PacketTemplate.h"
};


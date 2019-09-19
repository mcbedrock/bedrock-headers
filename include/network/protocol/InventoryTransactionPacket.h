#pragma once

#include "Packet.h"

struct InventoryTransactionPacket : Packet {
	// This packet is extremely complicated. I'm not going to reverse engineer every other struct that it uses.
	// Best bet if you want to read/write packets for now is implementing the virtual functions in your own class derived from packet
	// And reading/writing the binary stream based on PocketMine-MP's code
};

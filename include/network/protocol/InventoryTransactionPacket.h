#pragma once

#include "Packet.h"

// TODO: Despite my pessimism in the note I might do it some day :)
struct [[deprecated("This packet is extremely complicated. I'm not going to reverse engineer every other struct that it uses."
					"Best bet if you want to read/write packets for now is implementing the virtual functions in your own class derived from packet"
	 "and reading/writing the BinaryStream based on some server's code."
"")]] InventoryTransactionPacket : Packet {};

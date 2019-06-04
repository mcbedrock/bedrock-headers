#pragma once

#include "Packet.h"

/*

  _ZN12BinaryStream21writeUnsignedVarInt64Ey
  (uParm2,*(undefined4 *)(iParm1 + 0x28),*(undefined4 *)(iParm1 + 0x2c));
  _ZN12BinaryStream11writeVarIntEi(uParm2,*(undefined4 *)(iParm1 + 0x24));
  _ZN12BinaryStream11writeVarIntEi(uParm2,*(undefined4 *)(iParm1 + 0x14));
  _ZN12BinaryStream19writeUnsignedVarIntEj(uParm2,*(undefined4 *)(iParm1 + 0x18));
  _ZN12BinaryStream11writeVarIntEi(uParm2,*(undefined4 *)(iParm1 + 0x1c));
 _ZN12BinaryStream11writeVarIntEi(uParm2,*(undefined4 *)(iParm1 + 0x20))

 */

/**
 * Packet for updating player (eg. sneaking, sprinting, etc)
 */
struct PlayerActionPacket : Packet {
private:
	char filler[6];

public:
	int32_t i0, i1, i2, i3, i4; // 0x14 0x18 0x1c 0x20 0x24
	int64_t i5; // 0x28/0x2c entity ID?

	// TODO: Finish

#include "PacketTemplate.h"
};

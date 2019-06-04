#pragma once

#include "Packet.h"

/*
 * Reverse engineered by decompiling MobEffectPacket::write, running /effect, and print statements
 *
  _ZN12BinaryStream21writeUnsignedVarInt64Ey(uParm2,*(undefined4 *)(iParm1 + 0x14),*(undefined4 *)(iParm1 + 0x18));
  _ZN12BinaryStream9writeByteEh(uParm2,(uint)*(byte *)(iParm1 + 0x20));
  _ZN12BinaryStream11writeVarIntEi(uParm2,*(undefined4 *)(iParm1 + 0x24));
  _ZN12BinaryStream11writeVarIntEi(uParm2,*(undefined4 *)(iParm1 + 0x28));
  _ZN12BinaryStream9writeBoolEb(uParm2,(uint)*(byte *)(iParm1 + 0x2c));
  _ZN12BinaryStream11writeVarIntEi(uParm2,*(undefined4 *)(iParm1 + 0x1c));
 */

struct MobEffectPacket : Packet {
private:
	char filler[0x14];

public:
	// TODO: Finish

	uint32_t effectID, amplifier, particles; // 0x14 0x18 0x1c
	uint8_t c0; // 0x20 sometimes 4 when adding

private:
	char fillerr[3];

public:
	uint32_t i3, i4; // 0x24 0x28, i3 = 28 when removing, i4 idk
	uint8_t type; // 0x2c, add = 168, remove = 248, clear = 95

	MobEffectPacket(unsigned char playerSubIndex) : Packet(playerSubIndex) {};

#include "PacketTemplate.h"
};

#pragma once

#include "../NetworkIdentifier.h"

struct BinaryStream;
struct NetEventCallback;

struct Packet {
	int unk_4 = 2, unk_8 = 1;
	unsigned char playerSubIndex = 0;

	Packet(unsigned char playerSubIndex) : playerSubIndex(playerSubIndex) {}

	Packet(Packet const &packet) : unk_4(packet.unk_4), unk_8(packet.unk_8) {}

	virtual ~Packet() = 0;

	virtual void *getId() const = 0;

	virtual void *getName() const = 0;

	virtual void *write(BinaryStream &) const = 0;

	virtual void *read(BinaryStream &) = 0;

	virtual void *handle(NetworkIdentifier const &, NetEventCallback &) const = 0;

	virtual bool disallowBatching() const = 0;
};
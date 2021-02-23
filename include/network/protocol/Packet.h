#pragma once

#include "../NetworkIdentifier.h"
#include "../BinaryStream.h"
#include <string>
#include <memory>

struct NetEventCallback;

/*
 * Important: When creating a subclass include VirtualTemplate.h inside the class
 */
struct Packet {
	int unk_4 = 2, unk_8 = 1;
	unsigned char playerSubIndex = 0;
	char pad[0x17];
	//char pad[0x7];
	//void *handlerThunk; // dispatcher instance that handles this type of packet

	//Packet() = default;

	//Packet(unsigned char playerSubIndex) : playerSubIndex(playerSubIndex) {}

	//Packet(Packet const &packet) : unk_4(packet.unk_4), unk_8(packet.unk_8) {}

	// Change these in VirtualTemplate.h as well

	virtual ~Packet() = 0;

	virtual int getId() const = 0;

	virtual std::string getName() const = 0;

	virtual void write(BinaryStream &) const = 0;

	virtual void read(ReadOnlyBinaryStream &) = 0;

	virtual void handle(NetworkIdentifier const&, NetEventCallback &, std::shared_ptr<Packet>&);

	//virtual bool disallowBatching() const = 0;
};

//char (*_test)[offsetof(Packet, handlerThunk)] = 1;
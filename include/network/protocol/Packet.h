#pragma once

#include "../NetworkIdentifier.h"
#include "../BinaryStream.h"
#include <string>
#include <memory>

struct NetEventCallback;

/*
 * Important: When creating a subclass include VirtualTemplate.h inside the class
 */
#pragma pack(push, 4)
struct Packet {
	int unk_4 = 2, unk_8 = 1;
	char pad[0x8];
	uintptr_t **handlerThunk; // dispatcher instance that handles this type of packet (array, first item should be for this packet type)
	char pad2[0x4];

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
#pragma pack(pop)

static_assert(sizeof(Packet) == 0x24);
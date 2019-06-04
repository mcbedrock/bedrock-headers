#include "Packet.h"

struct DisconnectPacket : Packet {
	bool hideDisconnectionScreen = false;
	std::string message;

	DisconnectPacket(std::string message, bool value) : Packet(0), hideDisconnectionScreen(value), message(message) {}

#include "PacketTemplate.h"
};
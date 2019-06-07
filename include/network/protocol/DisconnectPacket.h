#include "Packet.h"

/**
 * Packet for gracefully disconnecting
 */
struct DisconnectPacket : Packet {
	bool hideDisconnectionScreen = false;
	std::string message;

	DisconnectPacket(std::string message, bool value) : Packet(0), hideDisconnectionScreen(value), message(message) {}

#include "VirtualTemplate.h"
};
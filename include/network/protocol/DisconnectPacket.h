#include "Packet.h"

/**
 * Packet for gracefully disconnecting
 */
struct DisconnectPacket : Packet {
	bool hideDisconnectionScreen;
	std::string message;

	DisconnectPacket(std::string message = "client disconnect", bool value = false) : hideDisconnectionScreen(value), message(message) {}

#include "VirtualTemplate.h"
};
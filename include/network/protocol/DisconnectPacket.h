#include "Packet.h"

/**
 * Packet for gracefully disconnecting
 */
struct DisconnectPacket : Packet {
	bool hideDisconnectionScreen;
	char pad[0x3]; // don't need to add this cause byte alignment?
	gsl::cstring_span message;

	DisconnectPacket(gsl::cstring_span message = "client disconnect", bool value = false) : hideDisconnectionScreen(value), message(message) {}

#include "VirtualTemplate.h"
};

static_assert(offsetof(DisconnectPacket, hideDisconnectionScreen) == 0x24);
static_assert(offsetof(DisconnectPacket, message) == 0x28);

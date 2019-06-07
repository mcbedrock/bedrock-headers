#pragma once

#include "Packet.h"

/*
 * Client -> Server
 */
struct ServerSettingsRequestPacket : Packet {
	ServerSettingsRequestPacket(unsigned char playerSubIndex) : Packet(playerSubIndex) {}

#include "VirtualTemplate.h"
};
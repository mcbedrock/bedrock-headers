#pragma once

#include "ModalFormRequestPacket.h"

/*
 * Server -> Client
 */
struct ServerSettingsResponsePacket : Packet {
	int formId;
	std::string formData;

	ServerSettingsResponsePacket(unsigned char playerSubIndex) : Packet(playerSubIndex) {}

#include "VirtualTemplate.h"
};
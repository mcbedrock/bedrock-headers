#pragma once

#include "Packet.h"
#include <string>

/*
 * Client -> Server
 */
struct ModalFormResponsePacket : Packet {
	int formId;
	std::string formData;

	ModalFormResponsePacket(unsigned char playerSubIndex) : Packet(playerSubIndex) {}

#include "VirtualTemplate.h"
};
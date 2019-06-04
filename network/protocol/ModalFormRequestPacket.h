#pragma once

#include "Packet.h"
#include <string>

/*
 * Server -> Client
 */
struct ModalFormRequestPacket : Packet {
	int formId;
	std::string formData;

	ModalFormRequestPacket(unsigned char playerSubIndex) : Packet(playerSubIndex) {}

#include "PacketTemplate.h"
};
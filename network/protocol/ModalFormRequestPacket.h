#pragma once

#include "Packet.h"
#include <string>

/*
 * Server -> Client
 */
class ModalFormRequestPacket : public Packet {
public:
	int formId;
	std::string formData;

	ModalFormRequestPacket(unsigned char playerSubIndex) : Packet(playerSubIndex) {}

	virtual void *getId() const;

	virtual void *getName() const;

	virtual void *write(BinaryStream &) const;

	virtual void *read(BinaryStream &);

	virtual void *handle(NetworkIdentifier const &, NetEventCallback &) const;

	virtual bool disallowBatching() const;
};
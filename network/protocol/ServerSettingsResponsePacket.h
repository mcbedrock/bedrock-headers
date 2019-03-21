#pragma once

#include "ModalFormRequestPacket.h"

/*
 * Server -> Client
 */
class ServerSettingsResponsePacket : public Packet {
public:
	int formId;
	std::string formData;

	ServerSettingsResponsePacket(unsigned char playerSubIndex) : Packet(playerSubIndex) {}

	virtual void *getId() const;

	virtual void *getName() const;

	virtual void *write(BinaryStream &) const;

	virtual void *read(BinaryStream &);

	virtual void *handle(NetworkIdentifier const &, NetEventCallback &) const;

	virtual bool disallowBatching() const;
};
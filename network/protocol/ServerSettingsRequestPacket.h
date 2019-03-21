#pragma once

#include "Packet.h"

/*
 * Client -> Server
 */
class ServerSettingsRequestPacket : public Packet {
public:
	ServerSettingsRequestPacket(unsigned char playerSubIndex) : Packet(playerSubIndex) {}

	virtual void *getId() const;

	virtual void *getName() const;

	virtual void *write(BinaryStream &) const;

	virtual void *read(BinaryStream &);

	virtual void *handle(NetworkIdentifier const &, NetEventCallback &) const;

	virtual bool disallowBatching() const;
};
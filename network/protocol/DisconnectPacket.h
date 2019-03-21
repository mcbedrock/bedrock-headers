#include "Packet.h"

class DisconnectPacket : public Packet {
public:
	bool hideDisconnectionScreen = false;
	std::string message;

	DisconnectPacket(std::string message, bool value) : Packet(0), hideDisconnectionScreen(value), message(message) {}

	virtual void *getId() const;

	virtual void *getName() const;

	virtual void *write(BinaryStream &) const;

	virtual void *read(BinaryStream &);

	virtual void *handle(NetworkIdentifier const &, NetEventCallback &) const;

	virtual bool disallowBatching() const;
};
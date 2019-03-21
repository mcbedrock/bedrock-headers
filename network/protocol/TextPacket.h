#pragma once

#include "Packet.h"
#include <string>
#include <vector>

struct TextPacket : Packet {
	enum class TextPacketType : unsigned char {
		RAW, CHAT, TRANSLATION, POPUP, JUKEBOX_POPUP, TIP, SYSTEM, WHISPER, ANNOUNCEMENT
	};

	TextPacketType type;
	std::string sender;
	std::string message;
	char filler[65];

	static TextPacket createSystemMessage(std::string const &);

	static TextPacket createChat(std::string const &, std::string const &, std::string const &, std::string const &);

	TextPacket(unsigned char playerSubIndex) : Packet(playerSubIndex) {}

	virtual void *getId() const;

	virtual void *getName() const;

	virtual void *write(BinaryStream &) const;

	virtual void *read(BinaryStream &);

	virtual void *handle(NetworkIdentifier const &, NetEventCallback &) const;

	virtual bool disallowBatching() const;
};
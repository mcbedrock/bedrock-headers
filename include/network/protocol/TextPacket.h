#pragma once

#include "Packet.h"
#include <string>
#include <vector>

/**
 * Packet for most main UI text elements
 *
 * TODO Test and fix
 */
struct TextPacket : Packet {
	enum class TextPacketType : unsigned char {
		RAW, CHAT, TRANSLATION, POPUP, JUKEBOX_POPUP, TIP, SYSTEM, WHISPER, ANNOUNCEMENT, JSON
	};

	TextPacketType type;
	std::string sender;
	std::string message;

private:
	char filler[65];

public:
	static TextPacket createSystemMessage(std::string const &);

	static TextPacket createChat(std::string const &, std::string const &, std::string const &, std::string const &);

	TextPacket(unsigned char playerSubIndex) : Packet(playerSubIndex) {}

#include "VirtualTemplate.h"
};
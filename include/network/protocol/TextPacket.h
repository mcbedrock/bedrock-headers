#pragma once

#include "Packet.h"
#include <string>
#include <utility>
#include <vector>

enum class TextPacketType : unsigned char {
	RAW, CHAT, TRANSLATION, POPUP, JUKEBOX_POPUP, TIP, SYSTEM, WHISPER, ANNOUNCEMENT, JSON
};

/**
 * Packet for most main UI text elements
 *
 * TODO Test and fix
 */
struct TextPacket : Packet {
	TextPacketType type;

private:
	char filler[0x7];

	// TODO: Nevermind the rest of the write function is too complicated for me atm lol

public:
	/*std::string message; // 0x1c
	std::vector<std::string> unk_1; // 0x20
	bool needsTranslation; // 0x2c
	std::string unk_2, unk_3; // 0x30 0x34

	TextPacket(TextPacketType type, std::string message) : type(type), message(std::move(message)) {}*/

	TextPacket(TextPacketType type, const std::string &, const std::string &, const std::vector<std::string> &, bool, const std::string &, const std::string &);

#include "VirtualTemplate.h"
};

//static_assert(offsetof(TextPacket, unk_2) == 0x30);

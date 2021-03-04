#pragma once

#include "Packet.h"
#include <string>
#include <utility>
#include <vector>

// Actual name
enum struct TextPacketType : char {
	RAW = 0,
	CHAT = 1,
	TRANSLATION = 2,
	POPUP = 3,
	JUKEBOX_POPUP = 4,
	TIP = 5,
	SYSTEM = 6,
	WHISPER = 7,
	ANNOUNCEMENT = 8,
	JSON = 9,
	WHISPER_JSON = 10
};

/**
 * Packet for most main UI text elements
 *
 * According to the offset jumps it must be storing them as normal std::strings ? probably uwp strings on win10/other editions
 */
struct TextPacket : Packet {
	TextPacketType type;
	char pad[0x17];

	/*std::string str1;
	std::string str2;*/

	// TODO: Nevermind the rest of the write function is too complicated for me atm lol

public:
	TextPacket(TextPacketType type, const std::string &, const std::string &, const std::vector<std::string> &, bool, const std::string &, const std::string &);

#include "VirtualTemplate.h"
};

static_assert(sizeof(std::string) == 0x18);
static_assert(offsetof(TextPacket, type) == 0x24);
/*static_assert(offsetof(TextPacket, str1) == 0x40);
static_assert(offsetof(TextPacket, str2) == 0x58);*/
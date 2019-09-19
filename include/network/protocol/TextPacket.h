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

private:
	char filler[0x7];

	// TODO: Nevermind the rest of the write function is too complicated for me atm lol

public:
	/*gsl::basic_string_span<char, -1> sender;
	gsl::basic_string_span<char, -1> message;
	bool needsTranslation;*/

#include "VirtualTemplate.h"
};

//static_assert(offsetof(TextPacket, sender) == 0x1c);


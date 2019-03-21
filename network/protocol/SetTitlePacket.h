#pragma once

#include "Packet.h"
#include <string>

class SetTitlePacket : public Packet {
public:
	enum class TitleType {
		CLEAR_TITLE = 0,
		RESET_TITLE,
		SET_TITLE,
		SET_SUBTITLE,
		SET_ACTIONBAR_MESSAGE,
		SET_ANIMATION_TIMES
	};

	TitleType type;
	std::string message;
	int fadeIn = 0;
	int stay = 0;
	int fadeOut = 0;

	SetTitlePacket(unsigned char playerSubIndex, int fadeIn, int stay, int fadeOut) : Packet(playerSubIndex),
																					  fadeIn(fadeIn), stay(stay),
																					  fadeOut(fadeOut) {}

	SetTitlePacket(unsigned char playerSubIndex, TitleType type) : Packet(playerSubIndex), type(type) {}

	virtual void *getId() const;

	virtual void *getName() const;

	virtual void *write(BinaryStream &) const;

	virtual void *read(BinaryStream &);

	virtual void *handle(NetworkIdentifier const &, NetEventCallback &) const;

	virtual bool disallowBatching() const;
};
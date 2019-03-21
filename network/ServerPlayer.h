#pragma once

#include "../Player.h"
#include "../gamemode/GameMode.h"
#include "../item/ItemInstance.h"
#include "../item/ItemUseCallback.h"
#include "../math/Vec3.h"
#include "protocol/Packet.h"
#include "protocol/TextPacket.h"
#include "protocol/SetTitlePacket.h"
#include "protocol/ModalFormRequestPacket.h"
#include "protocol/ModalFormResponsePacket.h"
#include "protocol/ServerSettingsRequestPacket.h"
#include "protocol/ServerSettingsResponsePacket.h"
#include "protocol/DisconnectPacket.h"

struct ServerPlayer : Player {
	void sendNetworkPacket(Packet &packet) const;

	void setPlayerGameType(GameType) override;

	void disconnect();

	void disconnect(const std::string &message) {
		DisconnectPacket pk{message, false};
		pk.playerSubIndex = getClientSubId();
		sendNetworkPacket(pk);
	}

	//Sends chat message to player
	void sendMessage(const std::string &message, TextPacket::TextPacketType type = TextPacket::TextPacketType::RAW) {
		auto pk = TextPacket::createSystemMessage(message);
		pk.type = type;
		sendNetworkPacket(pk);
	}

	void sendTip(const std::string &message) {
		sendMessage(message, TextPacket::TextPacketType::TIP);
	}

	//Adds a title text to the user's screen, with an optional subtitle.
	void addTitle(const std::string &title, const std::string &subtitle = "", int fadeIn = -1, int stay = -1,
				  int fadeOut = -1) {
		setTitleDuration(fadeIn, stay, fadeOut);
		if (!subtitle.empty()) {
			addSubTitle(subtitle);
		}
		sendTitleText(title, SetTitlePacket::TitleType::SET_TITLE);
	}

	//Sets the subtitle message, without sending a title.
	void addSubTitle(const std::string &message) {
		sendTitleText(message, SetTitlePacket::TitleType::SET_SUBTITLE);
	}

	//Adds small text to the user's screen.
	void addActionBarMessage(const std::string &message) {
		sendTitleText(message, SetTitlePacket::TitleType::SET_ACTIONBAR_MESSAGE);
	}

	//Removes the title from the client's screen.
	void removeTitles() {
		SetTitlePacket pk{this->getClientSubId(), SetTitlePacket::TitleType::CLEAR_TITLE};
		sendNetworkPacket(pk);
	}

	//Resets the title duration settings.
	void resetTitles() {
		SetTitlePacket pk{this->getClientSubId(), SetTitlePacket::TitleType::RESET_TITLE};
		sendNetworkPacket(pk);
	}

	//Sets the title duration.
	void setTitleDuration(int fadeIn, int stay, int fadeOut) {
		SetTitlePacket pk{this->getClientSubId(), fadeIn, stay, fadeOut};
		pk.type = SetTitlePacket::TitleType::SET_ANIMATION_TIMES;
		sendNetworkPacket(pk);
	}

	//Function used for sending titles.
	void sendTitleText(const std::string &message, SetTitlePacket::TitleType type) {
		SetTitlePacket pk{this->getClientSubId(), type};
		pk.message = message;
		sendNetworkPacket(pk);
	}
};
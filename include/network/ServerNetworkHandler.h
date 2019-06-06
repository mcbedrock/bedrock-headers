#pragma once

#include "NetworkHandler.h"
#include "ServerPlayer.h"

struct ServerNetworkHandler : NetworkHandler {
	void disconnectClient(NetworkIdentifier const &, std::string const &, bool);

	ServerPlayer *_getServerPlayer(NetworkIdentifier const &, unsigned char);
};
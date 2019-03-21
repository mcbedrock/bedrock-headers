#pragma once

#include "NetworkPeer.h"
#include "NetworkIdentifier.h"

struct NetworkHandler {
	NetworkPeer &getPeerForUser(NetworkIdentifier const &);
};
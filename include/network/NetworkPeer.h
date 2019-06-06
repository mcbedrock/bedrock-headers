#pragma once

#include "NetworkStats.h"

struct NetworkPeer {
	virtual ~NetworkPeer();

	virtual void sendPacket();

	virtual void receivePacket();

	virtual NetworkStats getNetworkStatus(void);
};
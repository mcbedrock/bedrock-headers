#pragma once

#include <memory>

struct NetworkStats {
	int32_t filler, ping, avgPing, maxBps;
	float packetLoss, avgPacketLoss;
};
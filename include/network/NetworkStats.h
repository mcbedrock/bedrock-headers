#pragma once

#include <memory>

struct NetworkStats {
private:
	int32_t filler;

public:
	int32_t ping, avgPing, maxBps;
	float packetLoss, avgPacketLoss;
};
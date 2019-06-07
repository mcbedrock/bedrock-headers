#pragma once

#include "Packet.h"

struct ActorFallPacket : Packet {
	/**
	 * Actor Runtime ID
	 */
	uint64_t entityID;

	/**
	 * Fall Distance
	 */
	float fallDistance;

	/**
	 * Actor below bedrock
	 */
	bool inVoid;
};
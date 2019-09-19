#pragma once

#include "Packet.h"

struct ActorFallPacket : Packet {
	/**
	 * Actor Runtime ID
	 */
	ActorRuntimeID rid;

	/**
	 * Fall Distance
	 */
	float fallDistance;

	/**
	 * Actor below bedrock
	 */
	bool inVoid;

#include "VirtualTemplate.h"
};
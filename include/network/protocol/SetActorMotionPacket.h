#pragma once

#include "Packet.h"

struct SetActorMotionPacket : Packet {
	/**
	 * Runtime ID of Actor
	 */
	uint64_t entityID;
	/**
	 * Motion
	 */
	float x, y, z;

#include "VirtualTemplate.h"
};
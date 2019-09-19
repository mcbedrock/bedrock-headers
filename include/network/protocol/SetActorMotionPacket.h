#pragma once

#include "Packet.h"
#include "util/ActorRuntimeID.h"
#include "math/Vec3.h"

struct SetActorMotionPacket : Packet {
	/**
	 * Runtime ID of Actor
	 */
	ActorRuntimeID rid;

	/**
	 * Motion (Full motion, not modifier. Calculate that.)
	 */
	union {
		struct {
			float x, y, z;
		};
		Vec3 motion;
	};

#include "VirtualTemplate.h"
};
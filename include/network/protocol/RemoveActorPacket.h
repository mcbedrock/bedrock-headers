#pragma once

#include "Packet.h"
#include "util/ActorRuntimeID.h"

/**
 * Packet for noting the client should destroy an entity with this UID
 */
struct RemoveActorPacket : Packet {
	ActorUniqueID uid;

#include "VirtualTemplate.h"
};

static_assert(offsetof(RemoveActorPacket, uid) == 0x28);
#pragma once

#include "mce/UUID.h"

struct ActorUniqueID {
	int64_t data;

	ActorUniqueID(int64_t data) : data(data) {};

	ActorUniqueID() : ActorUniqueID(0) {};

	operator int64_t() const {
		return data;
	};
};

struct ActorRuntimeID {
	uint64_t data;

	explicit ActorRuntimeID(uint64_t data) : data(data) {};

	ActorRuntimeID() : ActorRuntimeID(0) {};

	operator uint64_t() const {
		return data;
	}
};

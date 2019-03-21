#pragma once

#include "stdlib.h"
#include "../mce/UUID.h"

struct ActorUniqueID {
	int64_t data;

	ActorUniqueID(int64_t data) : data(data) {};

	ActorUniqueID() : ActorUniqueID(0) {};

	static ActorUniqueID fromClientId(int64_t);

	static ActorUniqueID fromUUID(mce::UUID const &);

	size_t getHash() const;

	operator bool() const;

	operator int64_t() const;

	bool operator!=(ActorUniqueID const &) const;

	bool operator==(ActorUniqueID const &) const;

	bool operator<(ActorUniqueID const &) const;

	ActorUniqueID &operator++();
};

struct ActorRuntimeID {
	int64_t data;

	ActorRuntimeID(int64_t data) : data(data) {};

	ActorRuntimeID() : ActorRuntimeID(0) {};

	size_t getHash() const;

	operator bool() const;

	bool operator!=(ActorUniqueID const &) const;

	ActorUniqueID &operator++();
};

namespace std {
	template<>
	struct hash<ActorUniqueID> {
		size_t operator()(ActorUniqueID const &v) const { return v.getHash(); }
	};

	template<>
	struct hash<ActorRuntimeID> {
		size_t operator()(ActorRuntimeID const &v) const { return v.getHash(); }
	};
}
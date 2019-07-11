#pragma once

struct Actor;

#include "util/ActorRuntimeID.h"
#include "util/ColorFormat.h"
#include "entity/ability/Abilities.h"
#include <functional>

class Player;

class ClientPlayerEventCoordinator;

struct Level {
	//Actor *getRuntimeEntity(ActorRuntimeID, bool) const;

	Actor *fetchEntity(ActorUniqueID, bool) const;

	Actor *getRuntimeEntity(ActorRuntimeID, bool) const;

	Player *getRuntimePlayer(ActorRuntimeID) const;

	void forEachPlayer(std::function<bool(Player const &)>) const;

	Abilities &getPlayerAbilities(ActorUniqueID const &);

	Abilities &getDefaultAbilities();

	void setPlayerAbilities(ActorUniqueID const &, Abilities);

	// TODO: Fix type
	//ColorFormat &getPlayerColor(Player const &) const;

	ClientPlayerEventCoordinator *getClientPlayerEventCoordinator();

	std::string getLevelId() const;

	bool isLeaveGameDone() const;
};

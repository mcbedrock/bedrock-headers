#pragma once

struct Actor;

#include "../../entity/ActorRuntimeID.h"
#include "../../util/ColorFormat.h"
#include "../../entity/Abilities.h"
#include <functional>

class Player;

class ClientPlayerEventCoordinator;

struct Level {
	//Actor *getRuntimeEntity(ActorRuntimeID, bool) const;

	Actor *fetchEntity(ActorUniqueID, bool) const;

	void forEachPlayer(std::function<bool(Player const &)>) const;

	Abilities &getPlayerAbilities(ActorUniqueID const &);

	Abilities &getDefaultAbilities();

	void setPlayerAbilities(ActorUniqueID const &, Abilities);

	// TODO: Fix type
	//ColorFormat &getPlayerColor(Player const &) const;

	ClientPlayerEventCoordinator *getClientPlayerEventCoordinator();
};

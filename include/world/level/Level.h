#pragma once

struct Actor;

#include "util/ActorRuntimeID.h"
#include "util/ColorFormat.h"
#include "entity/ability/Abilities.h"
#include "util/GameType.h"
#include "util/Color.h"
#include "world/HitResult.h"
#include "util/SmallSet.h"
#include <functional>
#include <vector>

struct Player;

class ClientPlayerEventCoordinator;

/**
 * Proudly done by hand...
 */

struct PlayerListEntry {
	ActorUniqueID uid;
	mce::UUID uuid;
	std::string name;
	std::string skinId;
	std::vector<unsigned char, std::allocator<unsigned char>> skinData;
	std::vector<unsigned char, std::allocator<unsigned char>> capeData;
	std::string geometryName;
	std::string geometryData;
	std::string xboxUserId;
	std::string platformChatId;

	PlayerListEntry(mce::UUID);

	PlayerListEntry(Player const &);
};

struct Level {
	uintptr_t **vtable;
	char pad[0x60];
	std::vector<Player *> players;
	char pad2[0x310];
	std::vector<Actor *> entities;
	char pad3[0x18C8];
	SmallSet<Actor *> globalEntities;

	Actor *fetchEntity(ActorUniqueID, bool) const;

	Actor *getRuntimeEntity(ActorRuntimeID, bool) const;

	HitResult &getHitResult();

	Player *getRuntimePlayer(ActorRuntimeID) const;

	Player *getPlayer(ActorUniqueID) const;

	Actor *getMob(ActorUniqueID) const;

	mce::Color getPlayerColor(Player const &) const;

	std::unordered_map<mce::UUID, PlayerListEntry> &getPlayerList();

	SmallSet<Actor *> &getGlobalEntities();

	void forEachPlayer(std::function<bool(Player const &)>) const;

	void forEachPlayer(std::function<bool(Player &)>);

	Abilities &getPlayerAbilities(ActorUniqueID const &);

	Abilities &getDefaultAbilities();

	void setPlayerAbilities(ActorUniqueID const &, Abilities);

	// TODO: Fix type
	//ColorFormat &getPlayerColor(Player const &) const;

	ClientPlayerEventCoordinator *getClientPlayerEventCoordinator();

	std::string getLevelId() const;

	bool isLeaveGameDone() const;

	void startLeaveGame();

	GameType getDefaultGameType() const;

	BlockPos getDefaultSpawn() const;

	unsigned int getActivePlayerCount() const;
};

static_assert(offsetof(Level, players) == 0x68);
static_assert(offsetof(Level, entities) == 0x390);
static_assert(offsetof(Level, globalEntities) == 0x1C70);
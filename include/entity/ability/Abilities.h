#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include "Ability.h"

struct CompoundTag;

enum struct PlayerPermissions : unsigned char;

enum struct CommandPermissionLevel : unsigned char {};

struct PermissionsHandler {
	CommandPermissionLevel permissionsLevel;  // 0
	PlayerPermissions playerPermissionsLevel; // 1
	PermissionsHandler();
	PermissionsHandler(PermissionsHandler const &);

	void addSaveData(CompoundTag &) const;
	bool loadSaveData(CompoundTag const &);

	CommandPermissionLevel getCommandPermissions() const;
	void setCommandPermissions(CommandPermissionLevel);
	PlayerPermissions getPlayerPermissions() const;
	void setPlayerPermissions(PlayerPermissions);
};


struct Abilities {
	std::unordered_map<std::string, Ability> abilityMap;

	std::vector<std::string> permissionNames;

	std::unordered_map<std::string, bool> customAbilities;

	Abilities(Abilities const &);

	Abilities();

	Abilities &operator=(Abilities const &);

	void _addTempCustomAbility(std::string const &);

	void _registerAbilities();

	void _registerAbility(std::string const &, Ability const &);

	Ability &getAbility(std::string const &);

	Ability &getAbility(std::string const &) const;

	bool getBool(std::string const &) const;

	bool getFloat(std::string const &) const;

	void setAbility(std::string const &, bool);

	void setAbility(std::string const &, float);

	void setAbilityDiff(std::string const &, bool, bool &);

	std::unordered_map<std::string, Ability> const &getAbilities() const;

	std::vector<std::string> const &getPermissionsAbilitiesNames() const;

	std::unordered_map<std::string, bool> const &getStoredCustomAbilities() const;

	CommandPermissionLevel getCommandPermissions() const;

	void setCommandPermissions(CommandPermissionLevel);

	PlayerPermissions getPlayerPermissions() const;

	void setPlayerPermissions(PlayerPermissions);

	void addSaveData(CompoundTag &) const;

	void loadSaveData(CompoundTag const &);

	bool isFlying() const;

	//~Abilities();

	static std::string INVULNERABLE;
	static std::string FLYING;
	static std::string MAYFLY;
	static std::string INSTABUILD;
	static std::string LIGHTNING;
	static std::string FLYSPEED;
	static std::string WALKSPEED;
	static std::string MUTED;
	static std::string WORLDBUILDER;
	static std::string NOCLIP;
	static std::string BUILD_AND_MINE;
	static std::string DOORS_AND_SWITCHES;
	static std::string OPEN_CONTAINERS;
	static std::string ATTACK_PLAYERS;
	static std::string ATTACK_MOBS;
	static std::string OPERATOR;
	static std::string TELEPORT;
};
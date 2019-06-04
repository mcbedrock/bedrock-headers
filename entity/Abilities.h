#pragma once

#include <string>
#include <unordered_map>
#include "Ability.h"

struct Abilities {
private:
	char filler[8]; // TODO: Permission Handler

public:
	std::unordered_map<std::string, Ability> abilityMap;

	std::vector<std::string> permissionNames;

	std::unordered_map<std::string, bool> customAbilities;

	Abilities(Abilities const &);

	Abilities();

	Abilities &operator=(Abilities const &);

	Ability *getAbility(std::string const &);

	Ability *getAbility(std::string const &) const;

	void setAbility(std::string const &, bool);

	void setAbility(std::string const &, float);

	void setAbilityDiff(std::string const &, bool, bool &);

	std::unordered_map<std::string, Ability> const &getAbilities() const;

	std::vector<std::string> const &getPermissionsAbilitiesNames() const;

	std::unordered_map<std::string, bool> const &getStoredCustomAbilities() const;

	bool isFlying() const;

	~Abilities();

	static std::string INSTABUILD;
	static std::string ATTACK_MOBS;
	static std::string INVULNERABLE;
	static std::string WORLDBUILDER;
	static std::string ATTACK_PLAYERS;
	static std::string OPEN_CONTAINERS;
	static std::string OPERATOR_COMMANDS;
	static std::string DOORS_AND_SWITCHES;
	static std::string TAG;
	static std::string MINE;
	static std::string BUILD;
	static std::string MUTED;
	static std::string FLYING;
	static std::string MAYFLY;
	static std::string NOCLIP;
	static std::string FLYSPEED
	static std::string TELEPORT;
	static std::string INVISIBLE;
	static std::string LIGHTNING;
	static std::string WALKSPEED;
};
#pragma once

#include <string>
#include "Ability.h"

struct Abilities {
	Ability *getAbility(std::string const &);

	void setAbility(std::string const &, bool);
};
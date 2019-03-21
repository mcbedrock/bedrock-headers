#pragma once

#include "Mob.h"
#include "../item/ItemInstance.h"

struct Player : Mob {
	ItemInstance *getSelectedItem() const;

	bool canUseAbility(std::string const &);
};
#pragma once

#include "item/Item.h"

struct BaseActorRenderContext;

struct ItemRenderer {
	void renderGuiItemNew(BaseActorRenderContext &, const ItemStack &, int, float, float, float, float, float, bool);
};
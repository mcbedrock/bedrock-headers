#pragma once

#include "Font.h"
#include "ItemRenderer.h"

struct BaseActorRenderContext {
	ItemRenderer &getItemRenderer();

	ScreenContext &getScreenContext();

	Font &getFont();
};
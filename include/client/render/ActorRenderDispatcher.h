#pragma once

#include "entity/Actor.h"
#include "BaseActorRenderContext.h"

struct ActorRenderDispatcher {
	BaseActorRenderContext &getRenderer(Actor const&) const;

	void render(BaseActorRenderContext&, Actor&, bool);
};

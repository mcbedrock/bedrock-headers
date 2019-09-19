#pragma once

#include "../../util/Color.h"
#include "ScreenContext.h"
#include <string>

// Not sure what this is atm
namespace mce {
	struct MaterialPtr;
}

struct Font {
	void drawShadow(ScreenContext&, std::string const &, float, float, Color const &, bool, mce::MaterialPtr*, float);
};
#pragma once

#include "ScreenContext.h"
#include <string>

struct Color;
// Not sure what this is atm
namespace mce {
	using MaterialPtr = void;
}

struct Font {
	void drawShadow(ScreenContext&, std::string const&, float, float, Color const&, bool, mce::MaterialPtr*, float);
};
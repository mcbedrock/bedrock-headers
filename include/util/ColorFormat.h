#pragma once

#include <string>
#include "Color.h"

struct ColorFormat {
	static const char DARK_GREEN,
			OBFUSCATED,
			DARK_PURPLE,
			LIGHT_PURPLE,
			RED,
			AQUA,
			BLUE,
			BOLD,
			GOLD,
			GRAY,
			BLACK,
			GREEN,
			RESET,
			WHITE,
			ESCAPE,
			ITALIC,
			YELLOW,
			DARK_RED,
			DARK_AQUA,
			DARK_BLUE,
			DARK_GRAY;

	static short FromString(const std::string &);

	static bool IsColorCode(const std::string &);

	static bool IsColorCode(char);

	static mce::Color *ColorFromChar(char);

	static char ColorCodeFromColor(const mce::Color &);

	static mce::Color *ColorFromColorCode(const std::string &);

	static std::string NameFromFormatCode(std::string const &);
};
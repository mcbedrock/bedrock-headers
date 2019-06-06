#pragma once

#include <string>

// TODO: Fix
struct ColorFormat {
	short DARK_GREEN,
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

	static short FromString(std::string const &);

	static bool IsColorCode(std::string const &);

	static bool IsColorCode(char);

	std::string NameFromFormatCode(std::string const &);
};
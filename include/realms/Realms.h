#pragma once

#include <string>

struct Realms {
	// TODO: find types
	static Realms *EMPTY_VERSION;

	std::string getUserAgent();
};

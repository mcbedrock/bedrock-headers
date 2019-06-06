#pragma once

#include <string>
#include <vector>
#include "CommandRegistry.h"
#include "../util/typeid.h"

enum struct CommandParameterDataType;

struct CommandParameterData {
private:
	char filler[0x28];

public:
	CommandParameterData(typeid_t<CommandRegistry>,
						 bool (CommandRegistry::*)(void *, CommandRegistry::ParseToken const &, CommandOrigin const &,
												   int, std::string &, std::vector<std::string> &) const, char const *,
						 CommandParameterDataType, char const *, int, bool, int);

	CommandParameterData(CommandParameterData const &);
};
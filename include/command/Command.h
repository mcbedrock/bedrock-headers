#pragma once

#include "../util/typeid.h"
#include "CommandRegistry.h"

struct CommandOutput;

struct Command {
private:
	char filler[0x10];

public:
	Command();

	virtual ~Command() = 0;

	virtual void execute(CommandOrigin const &, CommandOutput &) = 0;
};

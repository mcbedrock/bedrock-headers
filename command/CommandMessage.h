#pragma once

#include "../util/typeid.h"

struct CommandRegistry;

struct CommandOrigin;

struct CommandMessage {
private:
	char filler[0xC];

public:
	// NOTE: Even though this function is not part of this struct in MCPE, I am adding it there because it's much nicer
	// than using the symbol directly.
	static typeid_t<CommandRegistry> type_id() {
		static typeid_t<CommandRegistry> ret = type_id_minecraft_symbol<CommandRegistry>(
				"_ZZ7type_idI15CommandRegistry14CommandMessageE8typeid_tIT_EvE2id");
		return ret;
	};

	CommandMessage();

	~CommandMessage();

	std::string getMessage(CommandOrigin const &origin) const;
};
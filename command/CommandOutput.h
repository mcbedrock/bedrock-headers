#pragma once

#include <string>
#include <vector>

struct CommandOutputParameter;

enum struct CommandOutputMessageType {
	DEFAULT
};

struct CommandOutput {

public:

	void success();

	void addMessage(std::string const &, std::vector<CommandOutputParameter> const & = {},
					CommandOutputMessageType = CommandOutputMessageType::DEFAULT);

};

struct CommandOutputParameter {

private:
	std::string str;
	int type;

public:
	CommandOutputParameter(std::string const &);

	CommandOutputParameter(int);

};
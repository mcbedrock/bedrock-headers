#pragma once

namespace Json {
	struct Value {
		Value(const char *);

		std::string toStyledString() const;
	};
}
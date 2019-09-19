#pragma once

#include <map>
#include <string>
#include <memory>

struct PrintStream;

struct Tag {
	virtual ~Tag();
	virtual int getId() const = 0;
	virtual bool equals(Tag const &) const;
	virtual void print(PrintStream &) const;
};

struct CompoundTag : Tag {
	std::map<std::string, std::unique_ptr<Tag>> value;

	CompoundTag();

	CompoundTag(CompoundTag&&);

	bool isEmpty() const;

	int getId() const;
};
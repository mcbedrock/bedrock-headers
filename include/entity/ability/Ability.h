#pragma once

struct Ability {
	/*enum struct Type : char { Invalid = 0, Boolean = 1, Float = 2 };
	enum struct Options : char { Unset = 0, Saved = 1, Command = 2, Permission = 4 };
	union Value {
		bool val_bool;
		float val_float;
		Value(bool);
		Value(float);
		Value();
	};
	Type type;
	Value value;
	Options opts;

	Ability();
	Ability(float, Options);
	Ability(int, Options);
	*/

	char getType() const;

	bool getBool() const;

	float getFloat() const;

	void setBool(bool);

	void setFloat(float) const;

	//bool hasOption(Options) const;
};
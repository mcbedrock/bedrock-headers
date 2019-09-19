#pragma once

struct Brightness {
	static const Brightness
		*MAX,
		*MIN,
		*INVALID;

	unsigned char value;

	Brightness(unsigned char value) : value(value) {}
};
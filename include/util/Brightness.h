#pragma once

struct Brightness {
	static const Brightness
		MAX,
		MIN,
		INVALID;

	float value;

	Brightness(float value) : value(value) {}
};
#pragma once

struct Color {
	int toABGR() const;

	/**
	 * Create Color object from HSB
	 * @param hue
	 * @param saturation
	 * @param brightness
	 * @return Color
	 */
	unsigned int fromHSB(float hue, float saturation, float brightness);

	/**
	 * Get Color in hexadecimal
	 * @return std::string
	 * TODO: Verify
	 */
	std::string toHexString() const;

	static Color NIL,
			RED,
			BLUE,
			CYAN,
			GREY,
			PINK,
			BLACK,
			GREEN,
			WHITE,
			ORANGE,
			PURPLE,
			YELLOW;
};

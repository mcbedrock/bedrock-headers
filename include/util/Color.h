#pragma once

namespace mce {
	struct Color {
		static Color WHITE;
		static Color GREEN;
		static Color ORANGE;
		static Color NIL;
		static Color RED;
		static Color BLUE;
		static Color CYAN;
		static Color GREY;
		static Color BLACK;
		static Color PURPLE;
		static Color YELLOW;
		static Color SHADE_DOWN;
		static Color SHADE_WEST_EAST;
		static Color SHADE_NORTH_SOUTH;
		static Color SHADE_UP;

		int toABGR() const;

		int toARGB() const;

		/**
		 * Create Color object from HSB
		 * @param hue
		 * @param saturation
		 * @param brightness
		 * @return Color
		 */
		static Color fromHSB(float hue, float saturation, float brightness);

		/**
		 * Get Color in hexadecimal
		 * @return std::string
		 * TODO: Verify
		 */
		std::string toHexString() const;

		bool operator==(const Color &) const;
	};
}
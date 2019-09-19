#pragma once

struct Options {
	bool getFullscreen() const;

	void setHdrBrightness(float);

	int getPlayerViewPerspective();

	void setPlayerViewPerspective(int);
};

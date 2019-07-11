#pragma once

struct Mouse {
	static Mouse* _instance;

	static bool isButtonDown(int);

	static int getButtonState(int);

	static int getX();

	static int getY();
};
#pragma once

struct Agent {
	bool canShowNameTag() const;

	bool getAlwaysShowNameTag() const;

	bool isPushable() const;

	bool isPushableByPiston() const;

	void swingArm();

	bool isInvisible() const;

	bool isPickable();

	void setSelectedSlot(int);

	int getSelectedSlot() const;
};
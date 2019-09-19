#pragma once

#include <functional>

struct Timer {
	float tps;
	char pad_0004[4];
	float partialTicks;

	Timer(float, std::function<int()>);
	void advanceTime(float);
	void advanceTimeQuickly();
	float getAlpha() const;
	float getLastTimestep();
	unsigned getTicks() const;
	float getTime() const;
	float getTimeScale() const;
	int resetTimePassed();
	void setTimeScale(float);
	void skipTime();
	int stepTick(int);
	bool stepping() const;
};

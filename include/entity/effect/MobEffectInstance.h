#pragma once

#include <string>

struct MobEffectInstance {
	MobEffectInstance();

	MobEffectInstance(unsigned int id);

	MobEffectInstance(unsigned int id, int ticks);

	MobEffectInstance(unsigned int id, int ticks, int amplifier);

	MobEffectInstance(unsigned int id, int ticks, int amplifier, bool, bool particles, bool);

	MobEffectInstance(unsigned int id, int ticks, int amplifier, int, int, int, bool, bool, bool);

	int getId() const;

	int getAmplifier() const;

	std::string getDisplayName() const;

	int getDuration() const;

	int getLingerDuration() const;

	int getSplashDuration() const;

	int getDescriptionId() const;
};
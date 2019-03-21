#pragma once

struct MobEffectInstance {
	MobEffectInstance();

	MobEffectInstance(unsigned int id);

	MobEffectInstance(unsigned int id, int ticks);

	MobEffectInstance(unsigned int id, int ticks, int amplifier);

	MobEffectInstance(unsigned int id, int ticks, int amplifier, bool, bool);

	MobEffectInstance(unsigned int id, int ticks, int amplifier, int, int, int, bool, bool);

	int getId() const;

	int getAmplifier() const;

	std::string getDisplayName() const;
};
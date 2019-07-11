#pragma once

struct MobEffect {
	static MobEffect *getbyName(std::string const &);

	static MobEffect *getById(int);

	int getId();

	int getColor();

	bool isDisabled();

	static const MobEffect *DEFAULT_COLOR;
	static const MobEffect *MOVEMENT_SPEED;
	static const MobEffect *MOVEMENT_SLOWDOWN;
	static const MobEffect *DIG_SPEED;
	static const MobEffect *DIG_SLOWDOWN;
	static const MobEffect *DAMAGE_BOOST;
	static const MobEffect *HEAL;
	static const MobEffect *HARM;
	static const MobEffect *JUMP;
	static const MobEffect *CONFUSION;
	static const MobEffect *REGENERATION;
	static const MobEffect *DAMAGE_RESISTANCE;
	static const MobEffect *FIRE_RESISTANCE;
	static const MobEffect *WATER_BREATHING;
	static const MobEffect *INVISIBILITY;
	static const MobEffect *BLINDNESS;
	static const MobEffect *NIGHT_VISION;
	static const MobEffect *HUNGER;
	static const MobEffect *WEAKNESS;
	static const MobEffect *POISON;
	static const MobEffect *WITHER;
	static const MobEffect *HEALTH_BOOST;
	static const MobEffect *ABSORPTION;
	static const MobEffect *SATURATION;
	static const MobEffect *LEVITATION;
	static const MobEffect *FATAL_POISON;
	static const MobEffect *CONDUIT_POWER;
	static const MobEffect *SLOW_FALLING;
	static const MobEffect *BAD_OMEN;
	static const MobEffect *HERO_OF_THE_VILLAGE;
};
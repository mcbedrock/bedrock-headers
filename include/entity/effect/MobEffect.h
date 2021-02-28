#pragma once

#include "MobEffectInstance.h"
#include <string>

// TODO: NYI but size should not need to be known for pointers
struct Amplifier;
struct Attribute;
struct AttributeModifier;
struct AttributeBuff;

struct Actor;

struct MobEffect {
	MobEffect(int, const std::string &, const std::string &, bool, int, int, const std::string &, bool);
	void removeEffects(Actor *);
	void applyEffects(Actor *, int, int) const;
	int getId() const;
	static void initEffects(void *resourcePackManager);
	void addAttributeModifier(Attribute const &, std::shared_ptr<AttributeModifier>);
	void addAttributeBuff(Attribute const &, std::shared_ptr<AttributeBuff>);
	void setValueAmplifier(std::shared_ptr<Amplifier>);
	void setDurationAmplifier(std::shared_ptr<Amplifier>);
	static MobEffect *getByName(const std::string &);
	static MobEffect *getById(int);
	const std::string &getComponentName() const;
	const std::string &getResourceName() const;
	const std::string &getIconName() const;
	// some useless internals
	void applyInstantaneousEffect(Actor*, Actor*, Actor*, int, float) const;
	bool isHarmful() const;
	bool isInstantaneous() const;
	const mce::Color &getColor() const;
	bool isDisabled() const;
	bool isVisible() const;
	const std::string &formatDuration(MobEffectInstance const *);
	// return types for these?
	void clearAttributeBuffs();
	void clearAttributeModifiers();
	void getAttributeModifierValue(int, AttributeModifier const &) const;
	void viewAttributeModifiers() const;

	// bc62d48
	static const MobEffect *WEAKNESS;
	static const mce::Color DEFAULT_COLOR; // ???
	static const MobEffect *EMPTY_EFFECT;
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
	// bc62e50
	static const MobEffect **mMobEffects;
};
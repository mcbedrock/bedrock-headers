#pragma once

#include "ClientInstance.h"
#include "../network/NetworkHandler.h"
#include "../entity/LocalPlayer.h"
#include "options/Options.h"
#include "Minecraft.h"
#include <string>

struct GuiData;

struct MinecraftEventing;

struct Realms;

struct Player;

struct MinecraftGame {
public:
	static std::string WORLD_PATH;
	// TODO: find type
	static MinecraftGame *INTERACTION_FREQ_MS;

	MinecraftGame(int, char **);

	~MinecraftGame();

	void _initMinecraftGame();

	void setEduMode(bool);

	void setIsInGame(bool);

	void onTick();

	void onDimensionChanged();

	void onOptionsLoadBegin();

	void onPlayerLoaded(ClientInstance &, Player &);

	void onUserSignin();

	void handleBack(bool);

	GuiData *getPrimaryGuiData();

	Options *getPrimaryUserOptions();

	Realms *getRealms();

	bool isInGame() const;

	bool isInRealm();

	bool isEduMode() const;

	ClientInstance *getPrimaryClientInstance();

	LocalPlayer *getPrimaryLocalPlayer();

	// Crashes the game
	Minecraft *getPrimaryMinecraft();

	bool isLocalPlayer(ActorUniqueID const &) const;
};

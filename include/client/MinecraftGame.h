#pragma once

#include "ClientInstance.h"
#include "../network/NetworkHandler.h"
#include "../entity/LocalPlayer.h"
#include "../network/ExternalServer.h"
#include "../client/render/Font.h"
#include "../client/options/Options.h"
#include "Minecraft.h"
#include <string>

struct GuiData;

struct MinecraftEventing;

struct Realms;

struct Player;

// Does this inherit the Minecraft class? Or just similar field layout
struct MinecraftGame {
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

	Realms *getRealms();

	bool isInGame() const;

	bool isInRealm();

	bool isEduMode() const;

	ClientInstance *getPrimaryClientInstance();

	LocalPlayer *getPrimaryLocalPlayer();

	Font &getFont() const;

	//ExternalServer &getExternalServer() const;

	void startLeaveGame();

	bool isLeaveGameDone() const;
};

#pragma once

#include "network/NetworkHandler.h"
#include "client/options/Options.h"
#include "world/BlockTessellator.h"
#include "network/PacketSender.h"
#include "world/level/Level.h"
#include "gui/GuiData.h"
#include "render/Font.h"
#include "input/ClientInputHandler.h"
#include "events/ClientInstanceEventCoordinator.h"
#include "render/ActorRenderDispatcher.h"
#include "LevelRenderer.h"

struct MinecraftGame;

struct LevelRenderer;

struct LocalPlayer;

struct SceneStack {
	int getSize() const;
};

struct ClientInstance {
	/**
	 * Checks that player is playing and not busy in any UI
	 * @return bool
	 */
	bool isInGame() const;

	BlockTessellator& getBlockTessellator();

	/**
	 * Gets PacketSender
	 * @return LoopbackPacketSender
	 */
	PacketSender *getPacketSender();

	/**
	 * Get SceneStack
	 * @return SceneStack*
	 */
	 SceneStack *getClientSceneStack();

	/**
	 * Gets InputHandler for LocalPlayer
	 * @return ClientInputHandler
	 */
	ClientInputHandler &getInput() const;

	/*
	 *
	 */
	Options *getOptionsPtr();

	/**
	 * Gets EventCoordinator for LocalPlayer
	 * @return ClientInstanceEventCoordinator
	 */
	ClientInstanceEventCoordinator *getEventCoordinator();

	/**
	 * Gets primary game font
	 * @return Font
	 */
	Font &getFont() const;

	/**
	 * Gets current Controller ID
	 * @return int
	 */
	int getControllerId() const;

	/**
	 * Get ClientNetworkHandler
	 * @return NetworkHandler
	 */
	NetworkHandler *getClientNetworkSystem();

	MinecraftGame *getMinecraftGame() const;

	bool isLeavingGame() const;

	/**
	 * Is in a level
	 * @return
	 */
	bool isPlaying() const;

	bool isExitingLevel() const;

	bool isDestroyingGame() const;

	bool isReadyToRender() const;

	bool isPreGame() const;

	LevelRenderer *getLevelRenderer() const;

	MoveInputHandler *getMoveTurnInput();

	ActorRenderDispatcher &getEntityRenderDispatcher();

	void onClientInputInitComplete();

	void onClientCreatedLevel(std::unique_ptr<Level>, std::unique_ptr<LocalPlayer>);
};

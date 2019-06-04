#pragma once

struct ClientInstance;

struct Minecraft;

struct ClientInstanceEventCoordinator {
	void sendClientSuspend(ClientInstance &);

	void sendStartLeaveGame(ClientInstance &);

	void sendClientUpdateEnd(ClientInstance &);

	void sendClientUpdateStart(ClientInstance &);

	void sendClientCreatedLevel(ClientInstance &, Level &);

	void sendClientEnteredWorld(ClientInstance &);

	void sendClientInitializeEnd(ClientInstance &);

	void sendClientInitializeStart(ClientInstance &);

	void sendClientMinecraftInitialized(ClientInstance &, Minecraft &);
};
#pragma once

struct ClientInstance;

struct ClientInstanceEventCoordinator {
	void sendStartLeaveGame(ClientInstance &);
};
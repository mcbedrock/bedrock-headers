#pragma once

struct MinecraftScreenModel {
	/**
	 * Check if game is in trial mode
	 * @return bool
	 */
	bool isTrial() const;

	/**
	 * Check if realms are enabled
	 * @return bool
	 */
	bool isRealmsEnabled() const;
};

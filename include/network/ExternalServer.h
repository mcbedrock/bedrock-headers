#pragma once

struct ExternalServer {
	// TODO: Fix

	/**
	 * Get absolute IP address of server. Useful when trying to play on load-balancing servers with friends.
	 * @return std::string
	 */
	std::string getIP() const;

	/**
	 * Get server port
	 * @return int
	 */
	 int getPort() const;

	 /**
	  * Get advertised max plsyers
	  * @return int
	  */
	  int getMaxPlayers() const;

	 /**
	  * Get server version
	  * @return std::string
	  */
	 std::string getVersion() const;

	 /**
	  * Get server protocol
	  * @return std::string
	  */
	 std::string getProtocol() const;
};

#pragma once

struct ExternalServer {
	// TODO: Fix

	/**
	 * Get absolute IP address of server. Useful when trying to play on load-balancing servers with friends.
	 * @return std::string
	 */
	std::string const &getIP() const;

	/**
	 * Get server port
	 * @return int
	 */
	 int *getPort() const;

	 /**
	  * Get server version
	  * @return std::string
	  */
	 std::string const &getVersion() const;

	 /**
	  * Get server protocol
	  * @return std::string
	  */
	 std::string const &getProtocol() const;
};

#include <string>

struct ConnectionRequest {
	std::string getDeviceId() const;

	std::string getTenantId() const;

	std::string getDeviceModel() const;

	std::string getSelfSignedId() const;

	std::string getSkinGeometry() const;

	std::string getServerAddress() const;

	std::string getClientPlatformId() const;

	std::string getSkinGeometryName() const;

	std::string getGameVersionString() const;

	std::string getClientThirdPartyName() const;

	std::string getClientPlatformOnlineId() const;

	std::string getClientPlatformOfflineId() const;

	std::string getSkinId() const;

	int getDeviceOS() const;

	int getGuiScale() const;

	int getUIProfile() const;

	int getCurrentInputMode() const;

	int getDefaultInputMode() const;

	int getADRole() const;

	std::string toString();
};
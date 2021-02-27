#pragma once

struct AppPlatform {
	struct HardwareInformation {
		std::string deviceModel;
	};

	int getScreenWidth();

	int getScreenHeight();

	AppPlatform::HardwareInformation &getHardwareInformation() const;

	AppPlatform::HardwareInformation &getHardwareInformationToModify();

	const char *getPlatformRuntimeInformation() const;
};

struct AppPlatform_android : AppPlatform {
	void queueForMainThread(std::function<void()> function);
};
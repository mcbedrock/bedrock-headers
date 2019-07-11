#pragma once

struct AppPlatform {
	int getScreenWidth();

	int getScreenHeight();
};

struct AppPlatform_android : AppPlatform {
	void queueForMainThread(std::function<void()> function);
};
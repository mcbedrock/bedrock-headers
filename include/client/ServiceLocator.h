#pragma once

template<typename T>
struct ServiceLocator {
	static T &mService;
};
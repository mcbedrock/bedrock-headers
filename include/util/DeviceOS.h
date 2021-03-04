#pragma once

#include <cstdint>

enum struct DeviceOS : int32_t {
	Unknown = -1,
	Android = 1,
	iOS = 2,
	OSX = 3,
	Fire = 4,
	GearVR = 5,
	HoloLens = 6,
	Windows10 = 7,
	Win32 = 8,
	Dedicated = 9,
	TVOS = 10,
	Playstation = 11,
	NX = 12,
	Xbox = 13,
	WindowsPhone = 14 // lol
};
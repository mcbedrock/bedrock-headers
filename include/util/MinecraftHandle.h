#pragma once

#include <dlfcn.h>

namespace {
	void *MinecraftHandle() {
		static void *handle = dlopen("libminecraftpe.so", 0);
		return handle;
	}
}
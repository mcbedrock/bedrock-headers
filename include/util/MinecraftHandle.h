#pragma once

#include <dlfcn.h>

namespace {
	void *MinecraftHandle() {
		static void *handle = dlopen("libminecraftpe.so", RTLD_LAZY);
		return handle;
	}
}
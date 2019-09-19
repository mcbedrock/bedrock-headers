#pragma once

#include <string>
#include <item/Item.h>
#include <util/Json.h>

struct CommandUtils {
	static ItemStack createItemStack(const std::string &name, int, int);

	static ItemInstance createItemInstance(const Item *, int, int);

	static ItemInstance createItemInstance(const std::string &name, int, int);

	static bool addItemInstanceComponents(ItemInstance &targetItem, const Json::Value &json, std::string &outputMessge);

	//static std::string toJsonResult(const std::string &input, const Jsonca)
};
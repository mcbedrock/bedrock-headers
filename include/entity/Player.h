#pragma once

#include "item/Container.h"
#include "Mob.h"
#include "Agent.h"
#include "item/Item.h"
#include "util/Certificate.h"
#include "mce/Image.h"
#include "network/protocol/Packet.h"

struct SkinInfoData {
	char pad_0000[0x38];
	std::string &first, &second;
	mce::Image *getCapeImage() const;
	mce::Image *getSkinImage() const;
	//std::vector<unsigned char, std::allocator<unsigned char>> &getSkinImage() const;
	std::vector<unsigned char, std::allocator<unsigned char>> &getGeometryData() const;
	std::string &getSkinId() const;
	void setForceAlpha(std::vector<unsigned char, std::allocator<unsigned char> >&, int, int, int, int, int);
};

struct Player : Mob {
	PlayerInventory &getSupplies() const;
	bool canUseAbility(std::string const &);
	ItemInstance const &getSelectedItem() const;
	void setSelectedItem(ItemStack const &);
	void setSpeed(float);
	void sendNetworkPacket(Packet&) const;
	bool isUsingItem() const;
	short getSelectedItemSlot() const;
	void startSwimming();
	void stopSwimming();
	NetworkIdentifier const &getClientId() const;
	Facing::LookDirection::LookDirection getDirection() const;
	void setEnchantmentSeed(int);
	int getEnchantmentSeed() const;
	void stopGliding();
	void startGliding();
	void updateGliding();
	Agent *getAgent() const;
	bool isSleeping() const;
	bool isJumping();
	void displayClientMessage(std::string const&);
	const std::string &getPlatformOnlineId() const;
	Certificate *getCertificate() const;
	void startUsingItem(ItemStack const &, int);
	int getTicksUsingItem();
	SkinInfoData *getSkin() const;
	bool isLocalPlayer() const;
	void attack(Actor &);
	void feed(int);
	void normalTick();
	void move(Vec3 const &);
};
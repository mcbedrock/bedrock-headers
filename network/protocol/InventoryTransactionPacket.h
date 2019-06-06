#pragma once

#include <math/Vec3.h>
#include <item/ItemInstance.h>
#include <item/ItemStack.h>
#include "Packet.h"
#include "../../../mcpe-corruption/util/Log.h"


/**
 * Packet for Inventory moves and strangely for attacks
 */
struct InventoryTransactionPacket : Packet {
	uint32_t transactionType, actionCount;
	uint64_t entityID;
	uint32_t actionType;
	int hotbarSlot;
	ItemStack const &itemInHand;
	Vec3 playerPos, clickPos;

public:
	InventoryTransactionPacket(uint32_t transactionType, uint32_t actionCount, uint64_t entityID, uint32_t actionType, int hotbarSlot, ItemStack const &itemInHand, Vec3 playerPos, Vec3 clickPos) :
		transactionType(transactionType), actionCount(actionCount), entityID(entityID), actionType(actionType), hotbarSlot(hotbarSlot), itemInHand(itemInHand), playerPos(playerPos), clickPos(clickPos), Packet(0) {
		//
	}

	virtual int getId() const override;

	virtual std::string getName() const override;

	void write(BinaryStream &stream) const override {
		// NOTE: Only for use item on enttity transaction atm
		stream.writeUnsignedVarInt(transactionType);
		stream.writeUnsignedVarInt(actionCount);
		// TODO Write actions
		stream.writeUnsignedVarInt64(entityID);
		stream.writeUnsignedVarInt(actionType);
		stream.writeVarInt(hotbarSlot);

		//serialize<ItemStack>::write(itemInHand, stream);

		// TODO Make this a method for simplicity/find equiv
		{
			if (itemInHand.getId() != 0) {
				stream.writeVarInt(itemInHand.getId());

				stream.writeVarInt((itemInHand.getDamageValue() & 0xffff) << 8 | 1 /* count?) */);

				// TODO Send NBT data
				stream.writeUnsignedShort(0);

				stream.writeVarInt(0);
				stream.writeVarInt(0);

			} else {
				stream.writeVarInt(0);
			}
		}

		stream.writeFixedFloat(playerPos.x, 4);
		stream.writeFixedFloat(playerPos.y, 4);
		stream.writeFixedFloat(playerPos.z, 4);

		stream.writeFixedFloat(clickPos.x, 4);
		stream.writeFixedFloat(clickPos.y, 4);
		stream.writeFixedFloat(clickPos.z, 4);
	};

	void read(BinaryStream &stream) override {
		transactionType = stream.getUnsignedVarInt();

		actionCount = stream.getUnsignedVarInt();
		// TODO Read actions

		entityID = stream.getUnsignedVarInt64();
		actionType = stream.getUnsignedVarInt();
		hotbarSlot = stream.getVarInt();

		// TODO Read back item (dontreallycare)

		int px = stream.getFixedFloat(4);
		int py = stream.getFixedFloat(4);
		int pz = stream.getFixedFloat(4);
		playerPos = Vec3(px, py, pz);

		int cx = stream.getFixedFloat(4);
		int cy = stream.getFixedFloat(4);
		int cz = stream.getFixedFloat(4);
		clickPos = Vec3(cx, cy, cz);
	};

	virtual void handle(NetworkIdentifier const &, NetEventCallback &) const override;

	virtual bool disallowBatching() const override;

//private:
	// 0x14 + 4 - 13 (Packet size)
	//char filler[11]; // TODO: Find correct offset, been going at this for a while... I finally surrender (for tonight)
	//char filler[23];
	// trying to skip what appeared to be garbage:
	// 4060125436 4286912496 187359664
	//char filler[35];

//public:
	//uint32_t transactionType, actionsCount, entityID, i2, i3;

	// Offsets wouldn't work so I took it into my own hands
};


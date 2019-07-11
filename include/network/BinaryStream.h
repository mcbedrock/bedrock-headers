#pragma once

#include <item/Item.h>
#include <math/BlockPos.h>
#include <gsl/gsl>

struct ReadOnlyBinaryStream {
	long long getVarInt64();
	int getSignedInt();
	float getFixedFloat(double);
	long long getSignedInt64();
	short getSignedShort();
	unsigned int getUnsignedInt();
	unsigned char getUnsignedChar();
	unsigned long long getUnsignedInt64();
	unsigned short getUnsignedShort();
	unsigned int getUnsignedVarInt();
	float getNormalizedFloat();
	unsigned long long getUnsignedVarInt64();
	int getSignedBigEndianInt();
	bool getBool();
	unsigned char getByte();
	float getFloat();
	double getDouble();
	std::string const& getString();
	int getVarInt();
	float getByteRotation() {
		return (float)(getByte() * (360 / 256));
	}
};

struct BinaryStream : ReadOnlyBinaryStream {
	BinaryStream();
	void reset();
	void writeFloat(float);
	void writeDouble(double);
	void writeStream(BinaryStream&);
	void writeString(gsl::basic_string_span<char const, -1>);
	void writeVarInt(int);
	void writeVarInt64(long long);
	void writeSignedInt(int);
	void writeFixedFloat(float, double);
	void writeSignedInt64(long long);
	void writeSignedShort(short);
	void writeUnsignedInt(unsigned int);
	void writeUnsignedChar(unsigned char);
	void writeUnsignedInt64(unsigned long long);
	void writeUnsignedShort(unsigned short);
	void writeUnsignedVarInt(unsigned int);
	void writeNormalizedFloat(float);
	void writeUnsignedVarInt64(unsigned long long);
	void writeSignedBigEndianInt(int);
	void write(void const*, unsigned int);
	void writeBool(bool);
	void writeByte(unsigned char);
	// TODO These aren't in the game obviously, they're just useful adaptations from PMMP
	void writeSlot(const ItemStack *item) {
		if (!item || item->getId() == 0) {
			writeVarInt(0);
		} else {
			writeVarInt(item->getId());
			//writeVarInt((($item->getDamage() & 0x7fff) << 8)/* | item->getStackSize()*/)
			writeVarInt(item->getAuxValue()); // TODO Could be broken
			writeSignedShort(0); // TODO: NBT
			// I think these loop over the blocks 0-255
			// and write the ones that're true some way,
			// probably bitwise
			writeVarInt(0); // TODO: canPlaceOn
			writeVarInt(0); // TODO: canDestroy
			if (item->getId() == 513) // Shield
				writeUnsignedVarInt(0); // what...
		}
	}
	void writeSlot(const ContainerItemStack *item) {
		if (!item || item->getId() == 0) {
			writeVarInt(0);
		} else {
			writeVarInt(item->getId());
			writeVarInt(((item->getDamageValue() & 0x7fff) << 8) | item->getStackSize());
			writeSignedShort(0); // TODO: NBT
			// I think these loop over the blocks 0-255
			// and write the ones that're true some way,
			// probably bitwise
			writeVarInt(0); // TODO: canPlaceOn
			writeVarInt(0); // TODO: canDestroy
			if (item->getId() == 513) // Shield
				writeUnsignedVarInt(0); // what...
		}
	}
	void writeByteRotation(unsigned char rotation) {
		writeByte((int) (rotation / (360 / 256)));
	}
	void writeBlockPos(const BlockPos &pos) {
		writeVarInt(pos.x);
		writeUnsignedVarInt(pos.y);
		writeVarInt(pos.z);
	}
	void writeVec3(const Vec3 &vec3) {
		writeFloat(vec3.x);
		writeFloat(vec3.y);
		writeFloat(vec3.z);
	}
};

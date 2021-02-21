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
		return static_cast<float>(getByte() * (360 / 256));
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
	void writeVarInt64(long);
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
	void writeUnsignedVarInt64(unsigned long);
	void writeSignedBigEndianInt(int);
	void write(void const*, unsigned int);
	void writeBool(bool);
	void writeByte(unsigned char);
	// TODO These aren't in the game obviously, they're just useful adaptations from PMMP
	void writeByteRotation(unsigned char rotation) {
		writeByte(static_cast<int>(rotation / (360 / 256)));
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

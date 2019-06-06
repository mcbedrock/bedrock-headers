#pragma once

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
};

struct BinaryStream : ReadOnlyBinaryStream {
	void writeFloat(float);
	void writeDouble(double);
	void writeStream(BinaryStream&);
	void writeString(std::string const&);
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
};

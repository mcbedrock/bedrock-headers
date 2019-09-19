#pragma once

enum struct DataItemType : unsigned char {
	Byte,
	Short,
	Int,
	Float,
	String,
	CompoundTag,
	Pos,
	Long,
	Vec3
};

struct DataItem {
	char pad_0000[4];
	DataItemType type;
	char pad_0005[1];
	char id; // 0x6
	char pad_0006[5];
	char data; // 0xc, cast this address of this to whatever the type is
};

static_assert(offsetof(DataItem, data) == 0xc);
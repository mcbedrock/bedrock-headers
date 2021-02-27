#pragma once

// TODO: See if these x64 offsets are right

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
	uintptr_t **vtable;
	DataItemType type;
	char pad_0005[1];
	char id; // 0x6
	char pad_0006[5];
	union {
		uint8_t byteVal;
		uint16_t shortVal;
		uint32_t intVal;
		float floatVal;
		uint64_t longVal;
		BlockPos posVal;
		Vec3 vectorVal;
	};
};
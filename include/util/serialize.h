#pragma once

struct ReadOnlyBinaryStream;

struct BinaryStream;

template<typename T>
struct serialize {
	static void write(const T &, BinaryStream &);
	static T read(ReadOnlyBinaryStream &);
};

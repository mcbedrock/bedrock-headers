#pragma once

#include "Vec3.h"
#include "stdlib.h"
#include "stdio.h"

struct ChunkPos {
};

struct BlockPos {
	int x, y, z;

	//BlockPos(float, float, float);
	BlockPos(int x, int y, int z) : x(x), y(y), z(z) {};

	BlockPos(Vec3 const &);

	BlockPos(ChunkPos const &, int);

	BlockPos(BlockPos const &pos) : BlockPos(pos.x, pos.y, pos.z) {};

	BlockPos(int);

	BlockPos();

	static BlockPos MAX;
	static BlockPos MIN;
	static BlockPos ONE;
	static BlockPos ZERO;

	static BlockPos const &max(BlockPos const &pos1, BlockPos const &pos2);

	static BlockPos const &min(BlockPos const &, BlockPos const &);

	bool operator==(BlockPos const &) const;

	bool operator!=(BlockPos const &) const;

	BlockPos operator+(BlockPos const &) const;

	BlockPos operator+(int) const;

	BlockPos operator-(BlockPos const &) const;

	BlockPos operator-(int) const;

	BlockPos operator-() const;

	BlockPos operator*(int) const;

	BlockPos const &operator=(BlockPos const &);

	BlockPos const &operator+=(BlockPos const &);

	BlockPos const &operator-=(BlockPos const &);

	BlockPos const &operator*=(int);

	BlockPos above() const;

	BlockPos above(int) const;

	BlockPos below() const;

	BlockPos below(int) const;

	BlockPos east() const;

	BlockPos east(int) const;

	BlockPos south() const;

	BlockPos south(int) const;

	BlockPos west() const;

	BlockPos west(int) const;

	BlockPos north() const;

	BlockPos north(int) const;

	void set(BlockPos const &);

	void set(int, int, int);

	Vec3 center() const;

	float distSqr(BlockPos const &);

	float distSqr(float, float, float);
};
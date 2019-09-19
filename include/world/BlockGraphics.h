#pragma once

struct BlockGraphics {
	static BlockGraphics *mBlocks[256];

	void** vtable;

	Block &getBlock() const;
};
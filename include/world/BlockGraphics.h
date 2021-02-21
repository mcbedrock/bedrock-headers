#pragma once

struct BlockGraphics {
	static BlockGraphics *mBlocks[256];

	Block &getBlock() const;

	bool isFullAndOpaque(Block const &);
};
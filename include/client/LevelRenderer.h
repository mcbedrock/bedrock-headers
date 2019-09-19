#pragma once

#include <math/SubChunkPos.h>


struct LevelRendererCamera {
	void renderChunkImmediateChanged(const SubChunkPos &);
};

struct LevelRendererPlayer {
	//char pad_0000[0x5c];
	//LevelRendererCamera *levelRendererCamera;

	void computeCameraPos(float mode);
};


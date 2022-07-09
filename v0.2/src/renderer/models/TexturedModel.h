#pragma once
#include "RawModel.h"
#include "../Texture.h"
#include "../../terrain/mesh/BlockModel.h"
#include "../Loader.h"

class TexturedModel {
	Loader l;
	BlockModel bm;
	RawModel rm = l.loadToVAO(bm.getVertices(), 72, bm.getTex(), 48, bm.getIndices(), 36);
	Texture t = Texture("res/texture/block/dirt.png");
public:
	TexturedModel(RawModel rawM, Texture tex);	

	RawModel getModel() { return rm; }
	Texture getTexture() { return t; }
};
#pragma once

class RawModel {
	unsigned int vaoID;
	unsigned int vertexCount;

public:
	RawModel(unsigned int id, unsigned int vertCount);

	unsigned int getVaoID() { return vaoID; }
	unsigned int getVertexCount() { return vertexCount; }
};
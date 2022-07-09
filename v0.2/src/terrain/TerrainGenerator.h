#pragma once
#include <vector>
#include <GLM/glm/glm.hpp>
#include "mesh/Chunk.h"

class TerrainGenerator {

	const int renderDistBlocks = renderDistBlocks * chunkSize;
	const int worldSizeBlocks = 96;
	float noiseData[96][96];
	const int chunkHeight = 16;
	const int deviationFromChunkHeight = 12;

public:

	const int renderDistChunks = 4;
	const int chunkSize = 16;


	void generateHeights();
	void generateChunks(glm::vec3 camPos, std::vector<Chunk>& chunks);
	void generateBlocks1(std::vector<glm::vec3>& positions, glm::vec3 camPos);

};
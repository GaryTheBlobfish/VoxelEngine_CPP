#include "TerrainGenerator.h"

#include <algorithm>
#include "mesh/Block.h"
#include "../vendor/FastNoiseLite.h"
#include <random>
#include "mesh/Chunk.h"

std::vector<glm::vec3> usedPos;


void TerrainGenerator::generateHeights()
{
	int seed = rand() % 2000000000;
	FastNoiseLite noise = FastNoiseLite(seed);
	noise.SetSeed(seed);
	noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);

	if (seed % 2 == 0)
		noise.SetFractalType(FastNoiseLite::FractalType_Ridged);

	for (int y = 0; y < worldSizeBlocks; y++)
	{
		for (int x = 0; x < worldSizeBlocks; x++)
		{
			noiseData[x][y] = noise.GetNoise((float)x, (float)y) * deviationFromChunkHeight;
		}
	}

}

void TerrainGenerator::generateChunks(glm::vec3 camPos, std::vector<Chunk> &chunks)
{
	/*for (int x = (int)camPos.x; x < (int)camPos.x + renderDistChunks; x++) {
		for (int z = (int)camPos.z; z < (int)camPos.z + renderDistChunks; z++) {
	*/
	int chunkIndexX = 0;
	for (int x = 0; x < worldSizeBlocks / chunkSize; x++) {
		int chunkIndexZ = 0;
		for (int z = 0; z < worldSizeBlocks / chunkSize; z++) {
			glm::vec3 chunkPos = glm::vec3(chunkIndexX * chunkSize, 0, chunkIndexZ * chunkSize);
			if (!(std::find(usedPos.begin(), usedPos.end(), chunkPos) != usedPos.end())) {
				std::vector<Block> blocks;
				for (int cx = 0; cx < chunkSize; cx++) {
					for (int cz = 0; cz < chunkSize; cz++) {
						blocks.push_back(Block(glm::vec3(chunkPos.x + cx, chunkHeight + (int)noiseData[chunkIndexX * chunkSize + cx][chunkIndexZ * chunkSize + cz], chunkPos.z + cz)));
					}
				}
				usedPos.push_back(chunkPos);
				Chunk c = Chunk(chunkPos, blocks);
				chunks.push_back(c);

				blocks.clear();
			}
			chunkIndexZ++;
		}
		chunkIndexX++;
	}
	for (int x = (int)camPos.x; x > (int)camPos.x - renderDistChunks; x--) {
		for (int z = (int)camPos.z; z < (int)camPos.z + renderDistChunks; z++) {
		}
	}
	for (int x = (int)camPos.x; x > (int)camPos.x - renderDistChunks; x--) {
		for (int z = (int)camPos.z; z > (int)camPos.z - renderDistChunks; z--) {
		}
	}
	for (int x = (int)camPos.x; x < (int)camPos.x + renderDistChunks; x++) {
		for (int z = (int)camPos.z; z > (int)camPos.z - renderDistChunks; z--) {
		}
	}
}

void TerrainGenerator::generateBlocks1(std::vector<glm::vec3>& positions, glm::vec3 camPos)
{
	for (int x = (int)camPos.x; x < (int)camPos.x+8; x++) {
		for (int z = (int)camPos.z; z < (int)camPos.z+8; z++) {
			glm::vec3 v = glm::vec3(x, 0, z);
			if (!(std::find(usedPos.begin(), usedPos.end(),v) != usedPos.end())) {
				positions.push_back(v);
				usedPos.push_back(v);
			}
		}
	}
	for (int x = (int)camPos.x; x > (int)camPos.x - 8; x--) {
		for (int z = (int)camPos.z; z < (int)camPos.z + 8; z++) {
			glm::vec3 v = glm::vec3(x, 0, z);
			if (!(std::find(usedPos.begin(), usedPos.end(), v) != usedPos.end())) {
				positions.push_back(v);
				usedPos.push_back(v);
			}
		}
	}
	for (int x = (int)camPos.x; x > (int)camPos.x - 8; x--) {
		for (int z = (int)camPos.z; z > (int)camPos.z - 8; z--) {
			glm::vec3 v = glm::vec3(x, 0, z);
			if (!(std::find(usedPos.begin(), usedPos.end(), v) != usedPos.end())) {
				positions.push_back(v);
				usedPos.push_back(v);
			}
		}
	}
	for (int x = (int)camPos.x; x < (int)camPos.x + 8; x++) {
		for (int z = (int)camPos.z; z > (int)camPos.z - 8; z--) {
			glm::vec3 v = glm::vec3(x, 0, z);
			if (!(std::find(usedPos.begin(), usedPos.end(), v) != usedPos.end())) {
				positions.push_back(v);
				usedPos.push_back(v);
			}
		}
	}
}

#include "Chunk.h"

Chunk::Chunk(glm::vec3 position, std::vector<Block> blocks)
{
	this->pos = position;
	this->blocks = blocks;
}

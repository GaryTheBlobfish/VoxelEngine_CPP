#pragma once

#include <vector>
#include "Block.h"

class Chunk
{
	glm::vec3 pos = glm::vec3(0,0,0);

public:
	std::vector<Block> blocks;

	Chunk(glm::vec3 position, std::vector<Block> blocks);
};


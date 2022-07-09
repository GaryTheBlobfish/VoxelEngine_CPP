#pragma once

#include <GLM/glm/glm.hpp>

class Block {
	glm::vec3 position;

public:

	Block(glm::vec3 pos);

	glm::vec3 getPosition() { return position; }
};
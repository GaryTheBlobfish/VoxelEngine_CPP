#include "VAO.h"

#include <glad/glad.h>

VAO::VAO()
{
	glGenVertexArrays(1, &id);
	Bind();
}

void VAO::Bind()
{
	glBindVertexArray(id);
}

void VAO::UnBind()
{
	glBindVertexArray(0);
}

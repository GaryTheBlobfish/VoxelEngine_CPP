#include "VBO.h"
#include <glad/glad.h>

//float vertices[20] = {
//	// pos				 // tex coords
//	 0.5f,  0.5f, 0.0f,  1.0f, 1.0f,// top right
//	 0.5f, -0.5f, 0.0f,  1.0f, 0.0f,// bottom right
//	-0.5f, -0.5f, 0.0f,  0.0f, 0.0f,// bottom left
//	-0.5f,  0.5f, 0.0f,  0.0f, 1.0f// top left 
//};

const float HALF_SIZE = 0.5f; 

VBO::VBO()
{
	glGenBuffers(1, &id);
	Bind();
}

void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::UnBind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::GiveData(float data[], int size)
{
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}


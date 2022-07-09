#include "IBO.h"
#include <glad/glad.h>

int indices[] = {
				0,1,3,
				3,1,2,
				4,5,7,
				7,5,6,
				8,9,11,
				11,9,10,
				12,13,15,
				15,13,14,
				16,17,19,
				19,17,18,
				20,21,23,
				23,21,22
};

//unsigned int indices[] = {  // note that we start from 0!
//	0, 1, 3,   // first triangle
//	1, 2, 3    // second triangle
//};

IBO::IBO()
{
	glGenBuffers(1, &id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void IBO::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void IBO::UnBind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IBO::GiveData(unsigned int indices[], int size)
{
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}
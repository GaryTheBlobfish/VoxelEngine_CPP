#include "Loader.h"
#include <vector>
#include "shaders/VBO.h"
#include "shaders/VAO.h"
#include "shaders/IBO.h"
#include <glad/glad.h>

std::vector<unsigned int> vaos;
std::vector<unsigned int> vbos;
std::vector<unsigned int> ibos;


void Loader::storeDataInAttributeList(float data[], int sizeOfData, int index, int dimensions)
{
	VBO vbo = VBO();
	vbos.push_back(vbo.id);
	vbo.GiveData(data, sizeOfData);
	glVertexAttribPointer(index, dimensions, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(index);
}

void Loader::storeIndices(unsigned int indices[], int sizeOfIndices)
{
	IBO ibo = IBO();
	ibos.push_back(ibo.id);
	ibo.GiveData(indices, sizeOfIndices);
	
}

RawModel Loader::loadToVAO(float vertices[72], unsigned int sizeOfVert, float tex[48], unsigned int sizeOfTex, unsigned int indices[36], unsigned int sizeOfIndices)
{
	VAO vao = VAO();
	vaos.push_back(vao.id);
	storeDataInAttributeList(vertices, sizeOfVert * sizeof(float), 0, 3);
	storeDataInAttributeList(tex,      sizeOfTex  * sizeof(float),  1, 2);
	storeIndices(indices, sizeOfIndices           * sizeof(unsigned int));
	return RawModel(vao.id, sizeOfIndices         * sizeof(unsigned int));
}

void Loader::cleanUp()
{
	for (unsigned int id : vaos) {
		glDeleteVertexArrays(1, &id);
	}
	for (unsigned int id : vbos) {
		glDeleteBuffers(1, &id);
	}
	for (unsigned int id : ibos) {
		glDeleteBuffers(1, &id);
	}
}

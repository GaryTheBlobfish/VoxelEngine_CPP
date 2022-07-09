#include "Maths.h"

#include <GLM/glm/gtc/matrix_transform.hpp>

glm::mat4 Maths::makeProjMat(float FOV, int width, int height)
{
	return glm::perspective(glm::radians(FOV), (float)width/(float)height, 0.01f, 512.0f);
}

glm::mat4 Maths::makeTransMat(glm::vec3 trans, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ)
{
	glm::mat4 matrix = glm::mat4(1.0f);

	matrix = glm::translate(matrix, trans);
	matrix = glm::rotate(matrix, rotX, glm::vec3(1.0f, 0, 0));
	matrix = glm::rotate(matrix, rotY, glm::vec3(0, 1.0f, 0));
	matrix = glm::rotate(matrix, rotZ, glm::vec3(0, 0, 1.0f));
	matrix = glm::scale(matrix, glm::vec3(scaleX, scaleY, scaleZ));

	return matrix;
}

glm::mat4 Maths::makeViewMat(Camera cam)
{
	glm::mat4 mat = glm::mat4(1.0f);

	mat = glm::rotate(mat, glm::radians(cam.getRotX()), glm::vec3(1.0f, 0, 0));
	mat = glm::rotate(mat, glm::radians(cam.getRotY()), glm::vec3(0, 1.0f, 0));
	mat = glm::rotate(mat, glm::radians(cam.getRotZ()), glm::vec3(0, 0, 1.0f));
	mat = glm::translate(mat, glm::vec3(-cam.getPosition().x, -cam.getPosition().y, -cam.getPosition().z));

	return mat;
}

glm::mat4 Maths::makeViewMat(glm::vec3 transl)
{
	glm::mat4 mat = glm::mat4(1.0f);
	mat = glm::translate(mat, transl);
	return mat;
}

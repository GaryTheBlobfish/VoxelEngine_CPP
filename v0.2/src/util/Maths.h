#pragma once

#include <GLM/glm/glm.hpp>
#include "../entity/Camera.h"

#ifndef MATHS_H
#define MATHS_H
#endif

class Maths {

	inline static glm::vec3 X_axis = glm::vec3(1.0f, 0, 0);
	inline static glm::vec3 Y_axis = glm::vec3(0, 1.0f, 0);
	inline static glm::vec3 Z_axis = glm::vec3(0, 0, 1.0f);

public:
	static glm::mat4 makeProjMat(float FOV, int width, int height);
	static glm::mat4 makeTransMat(glm::vec3 trans, float rotX, float rotY, float rotZ, float scaleX, float scaleY, float scaleZ);
	static glm::mat4 makeViewMat(Camera cam);
	static glm::mat4 makeViewMat(glm::vec3 transl);
};
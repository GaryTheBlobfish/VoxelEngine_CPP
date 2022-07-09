#pragma once

#include <GLM/glm/glm.hpp>
#include <GLFW/glfw3.h>

#ifndef CAMERA_H
#define CAMERA_H
#endif


class Camera {

	float rotX = 0.0f;
	float rotY = 0.0f;
	float rotZ = 0.0f;

	const float speed = 8.0f;
	const float boost = speed / 2;

	glm::vec3 pos = glm::vec3(0,0,0);


public:
	Camera(glm::vec3 pos, float rotX, float rotY, float rotZ);

	float sensitivityModifier = 1.0f;

	void move(GLFWwindow* win, double delt);


	float getRotX();
	float getRotY();
	float getRotZ();

	glm::vec3 getPosition();

private:
	float sensitivity = 0.25f * sensitivityModifier;
};
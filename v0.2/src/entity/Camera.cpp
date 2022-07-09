#include "Camera.h"

Camera::Camera(glm::vec3 pos, float rotX, float rotY, float rotZ)
{
	this->pos = pos;
	this->rotX = rotX;
	this->rotY = rotY;
	this->rotZ = rotZ;
}

void Camera::move(GLFWwindow* win, double delt)
{
	float moveDirZ = 0;
	float moveDirX = 0;

	float dt = (float)delt;
	if (glfwGetKey(win, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		pos.y -= speed * dt;
	}
	else if (glfwGetKey(win, GLFW_KEY_SPACE) == GLFW_PRESS) {
		pos.y += speed * dt;
	}

	if (glfwGetKey(win, GLFW_KEY_W) == GLFW_PRESS) {
		moveDirZ -= speed * dt;
	}
	else if ((glfwGetKey(win, GLFW_KEY_W) == GLFW_PRESS) && (glfwGetKey(win, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)){
		moveDirZ -= (speed + boost) * dt;
	}
	else if (glfwGetKey(win, GLFW_KEY_S) == GLFW_PRESS) {
		moveDirZ += speed * dt;
	}

	if (glfwGetKey(win, GLFW_KEY_A) == GLFW_PRESS) {
		moveDirX -= speed * dt;
	}

	if (glfwGetKey(win, GLFW_KEY_D) == GLFW_PRESS) {
		moveDirX += speed * dt;
	}


	double xpos, ypos;
	glfwGetCursorPos(win, &xpos, &ypos);

	rotX += (float) ypos * sensitivity;
	rotY += (float) xpos * sensitivity;


	if (rotX >= 90.0f)
		rotX = 90.0f;
	else if (rotX <= -90.0f)
		rotX = -90.0f;
	
	float dx = (float)-(moveDirZ * sin(glm::radians(rotY)))+ (moveDirX * cos(glm::radians(rotY)));
	float dz = (float)(moveDirZ * cos(glm::radians(rotY))) + (moveDirX * sin(glm::radians(rotY)));

	pos += glm::vec3(dx, 0, dz);
}

float Camera::getRotX()
{
	return rotX;
}

float Camera::getRotY()
{
	return rotY;
}

float Camera::getRotZ()
{
	return rotZ;
}

glm::vec3 Camera::getPosition()
{
	return pos;
}

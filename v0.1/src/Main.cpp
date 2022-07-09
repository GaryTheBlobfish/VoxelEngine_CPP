#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "renderer/MasterRenderer.h"
#include "renderer/shaders/ShaderHandler.h"
#include "renderer/shaders/VAO.h"
#include "renderer/shaders/VBO.h"
#include "renderer/shaders/IBO.h"
#include "renderer/Texture.h"
#include <GLM/glm/glm.hpp>
#include <GLM/glm/gtc/matrix_transform.hpp>
#include "util/Maths.h"

#define NVSYNC 0
#define VSYNC 1
#define FOV 90.0f


glm::mat4 projection;

ShaderHandler sh;
void framebuffer_callback(GLFWwindow* win, int width, int height) {
	glViewport(0, 0, width, height);
	projection = Maths::makeProjMat(FOV, width, height);
}

int initialiseGLFW() {
	return glfwInit();
}


GLFWwindow* createWindowAndGLFWContext() {

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

	return glfwCreateWindow(1280, 720, "GaryTheBlobfish::VoxelEngine - C++ Edition v0.1", NULL, NULL);
}

int main() {

	
	/******************************** GLFW ********************************/

	if (!initialiseGLFW()) {
		std::cout << "ERR: Failed to initialise GLFW" << std::endl;
		return -1;
	}

	GLFWwindow *win = createWindowAndGLFWContext();
	if (win == NULL) {
		std::cout << "ERR: Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -2;
	}


	glfwMakeContextCurrent(win);
	glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSwapInterval(NVSYNC);


	/******************************** GLFW ********************************/
	/******************************** GLAD ********************************/
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialise GLAD" << std::endl;
		glfwTerminate();
		return -3;
	}
	glViewport(0, 0, 1280, 720);
	projection = Maths::makeProjMat(FOV, 1280, 720);
	glfwSetFramebufferSizeCallback(win, framebuffer_callback);
	
	/***************************** GAME LOOP ******************************/
	MasterRenderer r;
	VAO vao = VAO();
	vao.Bind();

	VBO vbo_vert = VBO();
	vbo_vert.GiveVertexData();
	sh.linkVertexAttribs();

	VBO vbo_tex = VBO();
	vbo_tex.GiveTexData();
	sh.linkTextureAttribs();

	IBO ibo = IBO();
	sh.setupVertexShader();
	sh.setupFragmentShader();
	sh.setupShaderProgram();
	Texture tex = Texture("res/texture/block/dirt.png");

	Camera cam = Camera(glm::vec3(0,0,2.0f), 0,0,0);





	double totalFPS = 0;
	double totalFrameCount = 0;
	double delt = 0.01;

	float degreesPerSecond = 10.0f;

	double TimeCounter = glfwGetTime();

	double FPSSecond = 0;
	double FrameCountSecond = 0;
	while (!glfwWindowShouldClose(win)) {
		double start = glfwGetTime();
		glfwPollEvents();

		// logic
		cam.move(win, delt);


		// rendering
		sh.BindShaderProg();
		sh.loadTransformationMatrix(Maths::makeTransMat(glm::vec3(0,0,-1.0f), 0.0f, 0.0f, 0.0f, 1, 1, 1));//Maths::makeTransMat(glm::vec3(0,0,0), 0, (float)glfwGetTime() * (float)delt, 0, 1, 1, 1));
		sh.loadViewMatrix(Maths::makeViewMat(cam));
		sh.loadProjectionMatrix(projection);
		r.prepare();
		sh.setUniformVec4("colour2", {sin(glfwGetTime()),cos(glfwGetTime()),1.0f,1.0f});
		tex.Bind(0);
		vao.Bind();
		ibo.Bind();


		r.render();

		vao.UnBind();
		sh.UnBindShaderProg();

		glfwSwapBuffers(win);

		glfwSetCursorPos(win, 0, 0);
		double finish = glfwGetTime();
		delt = finish - start;

		FPSSecond += 1 / delt;
		FrameCountSecond++;

		if ((glfwGetTime() - TimeCounter) >= 1) { // every second
			printf("%f%s%c", FPSSecond / FrameCountSecond, " FPS", '\n');
			TimeCounter = glfwGetTime();
			FPSSecond = 0;
			FrameCountSecond = 0;
		}
		totalFPS += 1 / delt;
		totalFrameCount++;
	}

	double avgFPS = totalFPS / totalFrameCount;
	std::cout << "avg FPS: " << avgFPS << std::endl;


	return 0;
}

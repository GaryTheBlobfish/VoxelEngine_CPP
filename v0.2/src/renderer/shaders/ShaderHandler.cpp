#include "ShaderHandler.h"

#include <glad/glad.h>
#include <iostream>
#include <GLM/glm/gtc/type_ptr.hpp>

const char* vertexSrc = 
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec2 aTexCoords;\n"
"out vec2 TexCoord;\n"
"out vec3 vertexColour;\n"

"uniform mat4 proj;\n"
"uniform mat4 view;\n"
"uniform mat4 model;\n"

"void main() {\n"
"	gl_Position = proj * view * model * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"	vertexColour = vec3(gl_Position.x, gl_Position.y, gl_Position.z);\n"
"	TexCoord = aTexCoords;\n"
"}\0";

const char* fragmentSrc =
"#version 330 core\n"
"out vec4 FragColour;\n"
"in vec3 vertexColour;\n"
"in vec2 TexCoord;\n"
"uniform sampler2D texSampler;\n"
"uniform vec4 colour2;\n"

"void main() {\n"
"	FragColour = texture(texSampler, TexCoord);// * colour2;\n"
"}\0";


void ShaderHandler::setupVertexShader()
{
	vsID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vsID, 1, &vertexSrc, NULL);
	glCompileShader(vsID);

	int success;
	char infoLog[512];
	glGetShaderiv(vsID, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vsID, 512, NULL, infoLog);
		std::cout << "ERR: Vertex shader failed to compile.\nmsg:\n" << infoLog << std::endl;
	}
}

void ShaderHandler::setupFragmentShader()
{
	fsID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fsID, 1, &fragmentSrc, NULL);
	glCompileShader(fsID);

	int success;
	char infoLog[512];
	glGetShaderiv(fsID, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fsID, 512, NULL, infoLog);
		std::cout << "ERR: Fragment shader failed to compile.\nmsg:\n" << infoLog << std::endl;
	}
}

void ShaderHandler::setupShaderProgram()
{
	int success;
	char infoLog[512];

	progID = glCreateProgram();
	glAttachShader(progID, vsID);
	glAttachShader(progID, fsID);
	glLinkProgram(progID);

	glGetProgramiv(progID, GL_LINK_STATUS, &success);

	if (!success) {
		glGetProgramInfoLog(progID, 512, NULL, infoLog);
		std::cout << "ERR: Shader program failed to link\nmsg:\n" << infoLog << std::endl;
	}
}

void ShaderHandler::linkVertexAttribs()
{
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void ShaderHandler::linkTextureAttribs()
{
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
}

void ShaderHandler::BindShaderProg()
{
	glUseProgram(progID);
}

void ShaderHandler::UnBindShaderProg()
{
	glUseProgram(0);
}

void ShaderHandler::setUniformVec2(const char* str, glm::vec2 v)
{
	glUniform2f(glGetUniformLocation(progID, str), v.x, v.y);
}

void ShaderHandler::setUniformVec3(const char* str, glm::vec3 v)
{
	glUniform3f(glGetUniformLocation(progID, str), v.x, v.y, v.z);
}

void ShaderHandler::setUniformVec4(const char* str, glm::vec4 v)
{
	glUniform4f(glGetUniformLocation(progID, str), v.x, v.y, v.z, v.w);
}

void ShaderHandler::setUniformFloat(const char* str, float f)
{
	glUniform1f(glGetUniformLocation(progID, str), f);
}

void ShaderHandler::setUniformInt(const char* str, int i)
{
	glUniform1i(glGetUniformLocation(progID, str), i);
}


void ShaderHandler::setUniformMat4(const char* str, glm::mat4 m) {
	glUniformMatrix4fv(glGetUniformLocation(progID, str), 1, GL_FALSE, &m[0][0]);
}

void ShaderHandler::loadProjectionMatrix(glm::mat4 m)
{
	setUniformMat4("proj", m);
}

void ShaderHandler::loadTransformationMatrix(glm::mat4 m) {
	glUniformMatrix4fv(glGetUniformLocation(progID, "model"), 1, GL_FALSE, glm::value_ptr(m));
}

void ShaderHandler::loadViewMatrix(glm::mat4 m) {
	setUniformMat4("view", m);
}
#pragma once

#include <GLM/glm/glm.hpp>


class ShaderHandler
{
	unsigned int vsID;
	unsigned int fsID;
	unsigned int progID;

public:
	void setupVertexShader();
	void setupFragmentShader();
	void setupShaderProgram();
	void linkVertexAttribs();
	void linkTextureAttribs();

	void BindShaderProg();
	void UnBindShaderProg();

	void setUniformVec2(const char* str, glm::vec2 v);
	void setUniformVec3(const char* str, glm::vec3 v);
	void setUniformVec4(const char* str, glm::vec4 v);

	void setUniformFloat(const char* str, float f);

	void setUniformInt(const char* str, int i);

	void setUniformMat4(const char* str, glm::mat4 m);

	void loadProjectionMatrix(glm::mat4 m);
	void loadTransformationMatrix(glm::mat4 m);
	void loadViewMatrix(glm::mat4 m);

};


#include "MasterRenderer.h"
#include <glad/glad.h>

void MasterRenderer::prepare()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.12f, 0.7f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void MasterRenderer::render() {
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}
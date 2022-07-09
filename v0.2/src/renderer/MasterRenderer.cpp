#include "MasterRenderer.h"
#include <glad/glad.h>

void MasterRenderer::prepare()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.2f, 0.7f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void MasterRenderer::render(TexturedModel tm) {
	tm.getTexture().Bind();
	glDrawElements(GL_TRIANGLES, tm.getModel().getVertexCount(), GL_UNSIGNED_INT, 0);
	glEnableVertexAttribArray(0);
}
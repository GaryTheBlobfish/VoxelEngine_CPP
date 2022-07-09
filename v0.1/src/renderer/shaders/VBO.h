#pragma once

#ifndef VBO_H
#define VBO_H
#endif // !VBO_H

class VBO
{
	unsigned int id;
public:
	VBO();
	void Bind();
	void UnBind();
	void GiveVertexData();
	void GiveTexData();
};


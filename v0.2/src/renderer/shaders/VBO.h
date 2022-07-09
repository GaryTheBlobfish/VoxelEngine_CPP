#pragma once

#ifndef VBO_H
#define VBO_H
#endif // !VBO_H

class VBO
{
public:
	unsigned int id;
	VBO();
	void Bind();
	void UnBind();
	void GiveData(float data[], int size);
};


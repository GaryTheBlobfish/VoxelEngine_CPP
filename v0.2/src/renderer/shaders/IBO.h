#pragma once

class IBO {
public:
	unsigned int id;
	IBO();
	void Bind();
	void UnBind();
	void GiveData(unsigned int indices[], int size);
};
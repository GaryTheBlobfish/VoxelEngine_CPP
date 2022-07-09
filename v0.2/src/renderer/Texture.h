#pragma once

class Texture {
	unsigned int id;
public:
	Texture(const char* path);
	void Bind();
	void setupTexWrapping(int mode);
	void setupTexFiltering(int mode);
};
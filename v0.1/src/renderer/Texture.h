#pragma once

class Texture {
	unsigned int id;
public:
	Texture(const char* path);
	void Bind(int texUnit);
	void setupTexWrapping(int mode);
	void setupTexFiltering(int mode);
};
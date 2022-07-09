#pragma once
#include "models/RawModel.h"
class Loader
{
	void storeDataInAttributeList(float data[], int sizeOfData, int index, int dimensions);
	void storeIndices(unsigned int indices[], int sizeOfIndices);
public:
	RawModel loadToVAO(float vertices[], unsigned  int sizeOfVert, float tex[], unsigned int sizeOfTex, unsigned int indices[], unsigned int sizeOfIndices);
	void cleanUp();
};


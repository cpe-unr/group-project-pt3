//Caitlin Hibler
//Date: 4/24/2021
//Purpose: PA3 - normalization.h file

#ifndef NORMALIZATION_H
#define NORMALIZATION_H
#include "Processor.h"

class Normalization : public Processor{
public:
	void processBuffer8M(unsigned char* buffer, int bufferSize) override;
	void processBuffer8S(unsigned char* buffer, int bufferSize) override;
	void processBuffer16M(signed char* buffer, int bufferSize) override;
	void processBuffer16S(signed char* buffer, int bufferSize) override;
};

#endif

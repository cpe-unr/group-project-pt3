//Caitlin Hibler
//Date: 4/24/2021
//Purpose: PT3 - Processor.h file

#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <cstdint>
#include <cmath>

class Processor {
public:
	virtual void processBuffer(unsigned char* buffer, int bufferSize) = 0;
	virtual void processBuffer(signed char* buffer, int bufferSize) = 0;

};

#endif 

//Caitlin Hibler
//Date: 4/24/2021
//Purpose: PT3 - Processor.h file

#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <cstdint>
#include <cmath>

/**
*This is the Processor class.
*/
class Processor {
public:
	/**
	*This is the Buffer for the 8bit mono. This is overriding the function from the Processor class.
	*@param buffer - the array we are looking through
	*@param bufferSize - the index of array
	*/
	virtual void processBuffer8M(unsigned char* buffer, int bufferSize) = 0;
	/**
	*This is the Buffer for the 8bit stereo. This is overriding the function from the Processor class.
	*@param buffer - the array we are looking through
	*@param bufferSize - the index of array
	*/
	virtual void processBuffer8S(unsigned char* buffer, int bufferSize) = 0;
	/**
	*This is the Buffer for the 16bit mono. This is overriding the function from the Processor class.
	*@param buffer - the array we are looking through
	*@param bufferSize - the index of array
	*/
	virtual void processBuffer16M(signed char* buffer, int bufferSize) = 0;
	/**
	*This is the Buffer for the 16bit stereo. This is overriding the function from the Processor class.
	*@param buffer - the array we are looking through
	*@param bufferSize - the index of array
	*/
	virtual void processBuffer16S(signed char* buffer, int bufferSize) = 0;
};

#endif 

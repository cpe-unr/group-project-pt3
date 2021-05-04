//Caitlin Hibler
//Date: 4/24/2021
//Purpose: PT3 - echo.h file

#ifndef ECHO_H
#define ECHO_H
#include "Processor.h"

/**
*This is the Echo class. It inherits from the Processor class.
*/
class Echo : public Processor{
	int delay;
public: 
	/**
	*This is the Echo parameterized constructor.
	*@param newDelay - the new int for delay once we read through the buffer
	*/
	Echo(int newDelay);
	
	/**
	*This is the Buffer for the 8bit mono. This is overriding the function from the Processor class.
	*@param buffer - the array we are looking through
	*@param bufferSize - the index of array
	*/
	void processBuffer8M(unsigned char* buffer, int bufferSize) override;

	/**
	*This is the Buffer for the 8bit stereo. This is overriding the function from the Processor class.
	*@param buffer - the array we are looking through
	*@param bufferSize - the index of array
	*/
	void processBuffer8S(unsigned char* buffer, int bufferSize) override;

	/**
	*This is the Buffer for the 16bit mono. This is overriding the function from the Processor class.
	*@param buffer - the array we are looking through
	*@param bufferSize - the index of array
	*/
	void processBuffer16M(signed char* buffer, int bufferSize) override;
	/**
	*This is the Buffer for the 16bit stereo. This is overriding the function from the Processor class.
	*@param buffer - the array we are looking through
	*@param bufferSize - the index of array
	*/
	void processBuffer16S(signed char* buffer, int bufferSize) override;
};
#endif


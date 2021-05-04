//Caitlin Hibler
//Date: 4/24/2021
//Purpose: PT3 - noisegate.h file

#ifndef NOISEGATE_H
#define NOISEGATE_H
#include "Processor.h"


/**
*This is the nosiegate class.
*/
class NoiseGate : public Processor{
	uint8_t threshold;
	int16_t threshold_2;
public:
	/**
	*This is the NoiseGate parameterized constructor.
	*@param newThreshold - the new threshold inputs given to the program from the main function. Used for uint8_t
	*@param newThreshold_2 - similar to newThreshold except it is for the int16_t
	*/
	NoiseGate(uint8_t newThreshold, int16_t newThreshold_2);

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

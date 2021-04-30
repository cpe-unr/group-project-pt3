//Caitlin Hibler
//Date: 4/24/2021
//Purpose: PT3 - noisegate.h file

#ifndef NOISEGATE_H
#define NOISEGATE_H
#include "Processor.h"

class NoiseGate : public Processor{
	uint8_t threshold;
public:
	NoiseGate(uint8_t newThreshold);

	void processBuffer(unsigned char* buffer, int bufferSize) override;

	void processBuffer(signed char* buffer, int bufferSize) override;
};

#endif

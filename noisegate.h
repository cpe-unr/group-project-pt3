//Caitlin Hibler
//Date: 4/24/2021
//Purpose: PT3 - noisegate.h file

#ifndef NOISEGATE_H
#define NOISEGATE_H
#include "Processor.h"

class NoiseGate : public Processor{
	uint8_t threshold;
	int16_t threshold_2;
public:
	NoiseGate(uint8_t newThreshold, int16_t newThreshold_2);

	void processBuffer8M(unsigned char* buffer, int bufferSize) override;
	void processBuffer8S(unsigned char* buffer, int bufferSize) override;
	void processBuffer16M(signed char* buffer, int bufferSize) override;
	void processBuffer16S(signed char* buffer, int bufferSize) override;
};

#endif

//Caitlin Hibler
//Date: 4/24/2021
//Purpose: PT3 - echo.h file

#ifndef ECHO_H
#define ECHO_H
#include "Processor.h"

class Echo : public Processor{
	int delay;
public: 
	Echo(int newDelay);
	
	void processBuffer8M(unsigned char* buffer, int bufferSize) override;
	void processBuffer8S(unsigned char* buffer, int bufferSize) override;
	void processBuffer16M(signed char* buffer, int bufferSize) override;
	void processBuffer16S(signed char* buffer, int bufferSize) override;
};
#endif


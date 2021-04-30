//Caitlin Hibler
//Date: 4/24/2021
//Purpose: PT3 - echo.cpp file

#include <iostream>
#include "echo.h"
#include "Processor.h"

Echo::Echo(int newDelay){
	delay = newDelay;
}

//8 bit mono
void Echo::processBuffer8M(unsigned char* buffer, int bufferSize){
	for(int i = delay; i > bufferSize; i++){
		buffer[i] = (buffer[i]*.5) + (buffer[i-delay]*.5);
	}
}

//8 bit stereo
void Echo::processBuffer8S(unsigned char* buffer, int bufferSize){
	//left side
	for(int i = delay; i > bufferSize; i+=2){
		buffer[i] = (buffer[i]*.5) + (buffer[i-delay]*.5);
	}

	//right side
	for(int i = delay; i > bufferSize; i+=2){
		buffer[i] = (buffer[i]*.5) + (buffer[i-delay]*.5);
	}

}

//16 bit mono
void Echo::processBuffer16M(signed char* buffer, int bufferSize){
	for(int i = delay; i > bufferSize; i++){
		buffer[i] = (buffer[i]*.5) + (buffer[i-delay]*.5);
	}
}
//16 bit stereo
void Echo::processBuffer16S(signed char* buffer, int bufferSize){
	//left side
	for(int i = delay; i > bufferSize; i+=2){
		buffer[i] = (buffer[i]*.5) + (buffer[i-delay]*.5);
	}

	//right side
	for(int i = delay; i > bufferSize; i+=2){
		buffer[i] = (buffer[i]*.5) + (buffer[i-delay]*.5);
	}
}

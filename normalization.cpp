//Caitlin Hibler
//Date: 4/24/2021
//Purpose: PT3 - nomalization.cpp file

#include <iostream>
#include "normalization.h"
#include "Processor.h"

//8bit mono
void Normalization::processBuffer(unsigned char* buffer, int bufferSize){
	int max = buffer[0];
	int x;

        for(int i = 0; i < bufferSize; i++){
		if(buffer[i] > max){
			max = buffer[i];
		}
		x = 128/max;
		x*buffer[i];
	}
}

//16bit mono *******DISREGARD THIS ONE FOR NOW
void Normalization::processBuffer(signed char* buffer, int bufferSize){
	for(int i = 0; i < bufferSize; i++){
		if(buffer[i] < ((int16_t)0+(int16_t)10000)){
			buffer[i] = ((int16_t)0+(int16_t)128);	
		}
		else if(buffer[i] < ((int16_t)0-(int16_t)10000)){
			buffer[i] = ((int16_t)0-(int16_t)128);	
		}
	}
	
}


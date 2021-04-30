//Caitlin Hibler
//Date: 4/24/2021
//Purpose: PT3 - noisegate.cpp file

#include "noisegate.h"
#include "Processor.h"
#include <iostream>

NoiseGate::NoiseGate(uint8_t newThreshold, int16_t newThreshold_2){
        threshold = newThreshold;
	threshold_2 = newThreshold_2;
}

//8bit mono
void NoiseGate::processBuffer8M(unsigned char* buffer, int bufferSize){
        for(int i = 0; i < bufferSize; i++){
                if(buffer[i] < ((uint8_t)128 + threshold) && buffer[i] > ((uint8_t)128 - threshold)){
                        buffer[i] = (uint8_t)128;
                }
        }
}

//8bit stereo
void NoiseGate::processBuffer8S(unsigned char* buffer, int bufferSize){
	//left side
	for(int i = 0; i < bufferSize; i+=2){
		if(buffer[i] < ((uint8_t)128 + threshold) && buffer[i] > ((uint8_t)128 - threshold)){
		buffer[i] = (uint8_t)128;
		}
	}
	//right side
	for(int i = 1; i < bufferSize; i+=2){
		if(buffer[i] < ((uint8_t)128 + threshold) && buffer[i] > ((uint8_t)128 - threshold)){
		buffer[i] = (uint8_t)128;
		}
	}
}

//16bit mono
void NoiseGate::processBuffer16M(signed char* buffer, int bufferSize){
	for(int i = 0; i < bufferSize; i++){
		if(buffer[i] < ((int16_t)0 + threshold) && buffer[i] > ((int16_t)0 - threshold)){
			buffer[i] = (int16_t)0;
		}
	}
}

//16bit stereo
void NoiseGate::processBuffer16S(signed char* buffer, int bufferSize){
	//left side
	for(int i = 0; i < bufferSize; i+=2){
		if(buffer[i] < ((int16_t)0 + threshold) && buffer[i] > ((int16_t)0 - threshold)){
			buffer[i] = (int16_t)0;
		}
	}

	//right side
	for(int i = 1; i < bufferSize; i+=2){
		if(buffer[i] < ((int16_t)0 + threshold) && buffer[i] > ((int16_t)0 - threshold)){
			buffer[i] = (int16_t)0;
		}
	}
}





//Caitlin Hibler
//Date: 4/24/2021
//Purpose: PT3 - noisegate.cpp file

#include "noisegate.h"
#include "Processor.h"
#include <iostream>

NoiseGate::NoiseGate(uint8_t newThreshold){
        threshold = newThreshold;
}

//8bit mono
void NoiseGate::processBuffer(unsigned char* buffer, int bufferSize){
        for(int i = 0; i < bufferSize; i++){
                if(buffer[i] < ((uint8_t)128 + threshold) && buffer[i] > ((uint8_t)128 - threshold)){
                        buffer[i] = (uint8_t)128;
                }
        }
}

//16bit mono
void NoiseGate::processBuffer(signed char* buffer, int bufferSize){
	for(int i = 0; i < bufferSize; i++){
		if(buffer[i] < ((int16_t)0 + threshold) && buffer[i] > ((int16_t)0 - threshold)){
			buffer[i] = (int16_t)0;
		}
	}
}

/* ***********STEREO INPUTS
//8bit stereo
void NoiseGate::processBuffer(unsigned char* buffer, int bufferSize){
	//left
        for(int i = 0; i < bufferSize; i+=2){
                if(buffer[i] < ((uint8_t)128 + threshold) && buffer[i] > ((uint8_t)128 - threshold)){
                        buffer[i] = (uint8_t)128;
                }
        }
	//right
        for(int i = 1; i < bufferSize; i+=2){
                if(buffer[i] < ((uint8_t)128 + threshold) && buffer[i] > ((uint8_t)128 - threshold)){
                        buffer[i] = (uint8_t)128;
                }
        }
}

//16bit stereo
void NoiseGate::processBuffer(signed char* buffer, int bufferSize){
	//left
        for(int i = 0; i < bufferSize; i+=2){
                if(buffer[i] < ((uint8_t)0 + threshold) && buffer[i] > ((uint8_t)0 - threshold)){
                        buffer[i] = (uint8_t)0;
                }
        }
	//right
        for(int i = 1; i < bufferSize; i+=2){
                if(buffer[i] < ((uint8_t)0 + threshold) && buffer[i] > ((uint8_t)0 - threshold)){
                        buffer[i] = (uint8_t)0;
                }
        }
}*/




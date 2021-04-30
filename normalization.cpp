//Caitlin Hibler
//Date: 4/24/2021
//Purpose: PT3 - nomalization.cpp file

#include <iostream>
#include "normalization.h"
#include "Processor.h"

//8bit mono
void Normalization::processBuffer8M(unsigned char* buffer, int bufferSize){
	int max = buffer[0];

        for(int i = 0; i < bufferSize; i++){
		if(buffer[i] > 128){
			buffer[i] += max;
		}
		else if(buffer[i] < 128){
			buffer[i] -= max;
		}
	}
	for(int i = 0; i < bufferSize; i++){
		if(buffer[i] > max || buffer[i] < (-1*max)){
			max = abs(buffer[i]);
		}
	}
}

//8bit stereo
void Normalization::processBuffer8S(unsigned char* buffer, int bufferSize){
	int max = buffer[0];

	//left side
        for(int i = 0; i < bufferSize; i+=2){
		if(buffer[i] > 128){
			buffer[i] += max;
		}
		else if(buffer[i] < 128){
			buffer[i] -= max;
		}
	}
	for(int i = 0; i < bufferSize; i+=2){
		if(buffer[i] > max || buffer[i] < (-1*max)){
			max = abs(buffer[i]);
		}
	}

	//right side
	for(int i = 1; i < bufferSize; i+=2){
		if(buffer[i] > 128){
			buffer[i] += max;
		}
		else if(buffer[i] < 128){
			buffer[i] -= max;
		}
	}
	for(int i = 1; i < bufferSize; i+=2){
		if(buffer[i] > max || buffer[i] < (-1*max)){
			max = abs(buffer[i]);
		}
	}
}

//16bit mono
void Normalization::processBuffer16M(signed char* buffer, int bufferSize){
	int max = buffer[0];

	for(int i = 0; i < bufferSize; i++){
		if(buffer[i] > 0){
			buffer[i] += max;
		}	
		else if(buffer[i] < 0){
			buffer[i] -=max;
		}
	}
	for(int i = 0; i < bufferSize; i++){
		if(buffer[i] > max || buffer[i] < (-1*max)){
			max = abs(buffer[i]);
		}
	}
}

void Normalization::processBuffer16S(signed char* buffer, int bufferSize){
	int max = buffer[0];
	//left side
	for(int i = 0; i < bufferSize; i+=2){
		if(buffer[i] > 0){
			buffer[i] += max;
		}	
		else if(buffer[i] < 0){
			buffer[i] -=max;
		}
	}
	for(int i = 0; i < bufferSize; i+=2){
		if(buffer[i] > max || buffer[i] < (-1*max)){
			max = abs(buffer[i]);
		}
	}

	//right side
	for(int i = 1; i < bufferSize; i+=2){
		if(buffer[i] > 0){
			buffer[i] += max;
		}	
		else if(buffer[i] < 0){
			buffer[i] -=max;
		}
	}
	for(int i = 1; i < bufferSize; i+=2){
		if(buffer[i] > max || buffer[i] < (-1*max)){
			max = abs(buffer[i]);
		}
	}
}


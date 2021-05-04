//Caitlin Hibler
//Date: 4/24/2021
//Purpose: PA3 - normalization.h file

#ifndef NORMALIZATION_H
#define NORMALIZATION_H
#include "Processor.h"

/**
*This is the Normalization class. It uses a template. 
*/
template <typename T>
class Normalization : public Processor{
public:
	/**
	*This is the Buffer for the 8bit mono. This is overriding the function from the Processor class.
	*@param buffer - the array we are looking through
	*@param bufferSize - the index of array
	*/
	void processBuffer8M(unsigned char* buffer, T bufferSize) override;
	/**
	*This is the Buffer for the 8bit stereo. This is overriding the function from the Processor class.
	*@param buffer - the array we are looking through
	*@param bufferSize - the index of array
	*/
	void processBuffer8S(unsigned char* buffer, T bufferSize) override;
	/**
	*This is the Buffer for the 8bit mono. This is overriding the function from the Processor class.
	*@param buffer - the array we are looking through
	*@param bufferSize - the index of array
	*/
	void processBuffer16M(signed char* buffer, T bufferSize) override;
	/**
	*This is the Buffer for the 8bit mono. This is overriding the function from the Processor class.
	*@param buffer - the array we are looking through
	*@param bufferSize - the index of array
	*/
	void processBuffer16S(signed char* buffer, T bufferSize) override;
};

//8bit mono
template <typename T>
void Normalization<T>::processBuffer8M(unsigned char* buffer, T bufferSize){
	T max = buffer[0];

        for(T i = 0; i < bufferSize; i++){
		if(buffer[i] > 128){
			buffer[i] += max;
		}
		else if(buffer[i] < 128){
			buffer[i] -= max;
		}
	}
	for(T i = 0; i < bufferSize; i++){
		if(buffer[i] > max || buffer[i] < (-1*max)){
			max = abs(buffer[i]);
		}
	}
}

//8bit stereo
template <typename T>
void Normalization<T>::processBuffer8S(unsigned char* buffer, T bufferSize){
	T max = buffer[0];

	//left side
        for(T i = 0; i < bufferSize; i+=2){
		if(buffer[i] > 128){
			buffer[i] += max;
		}
		else if(buffer[i] < 128){
			buffer[i] -= max;
		}
	}
	for(T i = 0; i < bufferSize; i+=2){
		if(buffer[i] > max || buffer[i] < (-1*max)){
			max = abs(buffer[i]);
		}
	}

	//right side
	for(T i = 1; i < bufferSize; i+=2){
		if(buffer[i] > 128){
			buffer[i] += max;
		}
		else if(buffer[i] < 128){
			buffer[i] -= max;
		}
	}
	for(T i = 1; i < bufferSize; i+=2){
		if(buffer[i] > max || buffer[i] < (-1*max)){
			max = abs(buffer[i]);
		}
	}
}

//16bit mono
template <typename T>
void Normalization<T>::processBuffer16M(signed char* buffer, T bufferSize){
	T max = buffer[0];

	for(T i = 0; i < bufferSize; i++){
		if(buffer[i] > 0){
			buffer[i] += max;
		}	
		else if(buffer[i] < 0){
			buffer[i] -=max;
		}
	}
	for(T i = 0; i < bufferSize; i++){
		if(buffer[i] > max || buffer[i] < (-1*max)){
			max = abs(buffer[i]);
		}
	}
}

//16 bit stero
template <typename T>
void Normalization<T>::processBuffer16S(signed char* buffer, T bufferSize){
	T max = buffer[0];
	//left side
	for(T i = 0; i < bufferSize; i+=2){
		if(buffer[i] > 0){
			buffer[i] += max;
		}	
		else if(buffer[i] < 0){
			buffer[i] -=max;
		}
	}
	for(T i = 0; i < bufferSize; i+=2){
		if(buffer[i] > max || buffer[i] < (-1*max)){
			max = abs(buffer[i]);
		}
	}

	//right side
	for(T i = 1; i < bufferSize; i+=2){
		if(buffer[i] > 0){
			buffer[i] += max;
		}	
		else if(buffer[i] < 0){
			buffer[i] -=max;
		}
	}
	for(T i = 1; i < bufferSize; i+=2){
		if(buffer[i] > max || buffer[i] < (-1*max)){
			max = abs(buffer[i]);
		}
	}
}


#endif

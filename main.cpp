//Group 3 teammates: Joshua Anderson and Caitlin Hibler
//Final project
//Due Date: May 2, 2021


/** @file */
#include "wav.h"
#include "echo.h"
#include "noisegate.h"
#include "normalization.h"
#include "Processor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>

int main(){

	Wav firstWav;
	//firstWav.readFile("yes-8-bit-mono.wav");
	firstWav.readFile("z.wav");
	firstWav.printMeta();
	//firstWav.writeFile("z.wav");
	firstWav.writeFile("zz.wav");

    return 0;

}


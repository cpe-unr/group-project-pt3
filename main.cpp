//Group 3 teammates: Joshua Anderson and Caitlin Hibler
//Final project
//Due Date: May 2, 2021


/** 
* Main file that creates the new audio files.
*/
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

int main(int argc, char *argv[]){
	if(argc != 2){
		std::cout << "Correct Usage: " << argv[0] << " <filename>" << std::endl;
	}
	else{
		if(std::string(argv[1]) == "yes-8-bit-mono.wav"){
			//8 bit mono
			Wav firstWav;
			//firstWav.readFile("yes-8-bit-mono.wav");
			firstWav.readFile("yes-8-bit-mono.wav");
			firstWav.printMeta();
			Processor *processor = new Echo(20000);
			processor->processBuffer8M(firstWav.getBuffer(), firstWav.getBufferSize());
			//firstWav.writeFile("z.wav");
			firstWav.writeFile("echo-8-bit-mono.wav");
			delete processor;

			Wav firstWav1;
			firstWav1.readFile("yes-8-bit-mono.wav");
			firstWav1.printMeta();
			Processor *processorNorm8M = new Normalization<int>();
			processorNorm8M->processBuffer8M(firstWav1.getBuffer(), firstWav1.getBufferSize());
			firstWav1.writeFile("norm-8-bit-mono.wav");
			delete processorNorm8M;

			Wav firstWav2;
			firstWav2.readFile("yes-8-bit-mono.wav");
			firstWav2.printMeta();
			Processor *processorNoise8M = new NoiseGate(10, 5000);
			processorNoise8M->processBuffer8M(firstWav2.getBuffer(), firstWav2.getBufferSize());
			firstWav2.writeFile("noise-8-bit-mono.wav");
			delete processorNoise8M;
		}//end of if for 8 bit mono

		else if(std::string(argv[1]) == "yes-8-bit-stereo.wav"){
			//8 bit stereo
			Wav secondWav;
			secondWav.readFile("yes-8-bit-stereo.wav");
			secondWav.printMeta();
			Processor *processorEcho8S = new Echo(20000);
			processorEcho8S->processBuffer8S(secondWav.getBuffer(), secondWav.getBufferSize());
			secondWav.writeFile("echo-8-bit-stereo.wav");
			delete processorEcho8S;

			Wav secondWav1;
			secondWav1.readFile("yes-8-bit-stereo.wav");
			secondWav1.printMeta();
			Processor *processorNorm8S = new Normalization<int>();
			processorNorm8S->processBuffer8S(secondWav1.getBuffer(), secondWav1.getBufferSize());
			secondWav1.writeFile("norm-8-bit-stereo.wav");
			delete processorNorm8S;

			Wav secondWav2;
			secondWav2.readFile("yes-8-bit-stereo.wav");
			secondWav2.printMeta();
			Processor *processorNoise8S = new NoiseGate(10, 5000);
			processorNoise8S->processBuffer8S(secondWav2.getBuffer(), secondWav2.getBufferSize());
			secondWav2.writeFile("noise-8-bit-stereo.wav");
			delete processorNoise8S;
		}//end of if for 8 bit stereo
	

		else if(std::string(argv[1]) == "yes-16-bit-mono.wav"){
			//16 bit mono
			Wav thirdWav;
			thirdWav.readFile("yes-16-bit-mono.wav");
			thirdWav.printMeta();
			Processor *processorEcho16M = new Echo(20000);
			processorEcho16M->processBuffer16M(thirdWav.getBuffer2(), thirdWav.getBufferSize());
			thirdWav.writeFile("echo-16-bit-mono.wav");
			delete processorEcho16M;
			
			Wav thirdWav1;
			thirdWav1.readFile("yes-16-bit-mono.wav");
			thirdWav1.printMeta();
			Processor *processorNorm16M = new Normalization<int>();
			processorNorm16M->processBuffer16M(thirdWav1.getBuffer2(), thirdWav1.getBufferSize());
			thirdWav1.writeFile("norm-16-bit-mono.wav");
			delete processorNorm16M;

			Wav thirdWav2;
			thirdWav2.readFile("yes-16-bit-mono.wav");
			thirdWav2.printMeta();
			Processor *processorNoise16M = new NoiseGate(10, 5000);
			processorNoise16M->processBuffer16M(thirdWav2.getBuffer2(), thirdWav2.getBufferSize());
			thirdWav2.writeFile("noise-16-bit-mono.wav");
			delete processorNoise16M;
		}//end of if 16 bit mono

	else if(std::string(argv[1]) == "yes-16-bit-stereo.wav"){
			//16 bit stereo
		 	Wav fourthWav;
			fourthWav.readFile("yes-16-bit-stereo.wav");
			fourthWav.printMeta();
			Processor *processorEcho16S = new Echo(20000);
			processorEcho16S->processBuffer16S(fourthWav.getBuffer2(), fourthWav.getBufferSize());
			fourthWav.writeFile("echo-16-bit-stereo.wav");
			delete processorEcho16S;

			Wav fourthWav1;
			fourthWav1.readFile("yes-16-bit-stereo.wav");
			fourthWav1.printMeta();
			Processor *processorNorm16S = new Normalization<int>();
			processorNorm16S->processBuffer16S(fourthWav1.getBuffer2(), fourthWav1.getBufferSize());
			fourthWav1.writeFile("norm-16-bit-stereo.wav");
			delete processorNorm16S;

			Wav fourthWav2;
			fourthWav2.readFile("yes-16-bit-stereo.wav");
			fourthWav2.printMeta();
			Processor *processorNoise16S = new NoiseGate(10,5000);
			processorNoise16S->processBuffer16S(fourthWav2.getBuffer2(), fourthWav2.getBufferSize());
			fourthWav2.writeFile("noise-16-bit-stereo.wav");
			delete processorNoise16S;
		}//end of if for 16 bit stereo
	}//end of else statement

    return 0;

}


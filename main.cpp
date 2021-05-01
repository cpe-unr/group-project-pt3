#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>

#include "wav.h"

int main() {
	Wav firstWav;
	//firstWav.readFile("yes-8-bit-mono.wav");
	firstWav.readFile("z.wav");
	firstWav.printMeta();
	//firstWav.writeFile("z.wav");
	firstWav.writeFile("zz.wav");

}


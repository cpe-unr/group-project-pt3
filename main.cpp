#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>

#include <unistd.h>
#include <dirent.h>
#include "wav.h"
#include "ui.h"

std::vector<std::string> getWavFiles(char* directory);


int main() {
	ui ui;
	
	char folder[256];
    	getcwd(folder, 256);
	std::vector<std::string> filePaths = getWavFiles(folder);
	std::vector<Wav*> wavs;
	ui.applyLabel("Importing all of the .wav files in the same directory as the program");
	std::string lof = "";
	for(std::string fp : filePaths){
		lof += " | " + fp + " |";
	}
	std::string userIn = ui.getStringMatch("The Files to be imported are: " + lof +" Would you like to import them? [yes,no]", {"yes","no"});
	if(userIn == "yes") {
		for(std::string file : filePaths) {
			Wav* tempWav = new Wav();
			ui.applyLabel("Importing: " + file);
			tempWav->readFile(file);
			wavs.push_back(tempWav);
		}
		ui.applyLabel("All files read in. Ready for use.");


	} else {
		ui.applyLabel("Files are not imported");
	}
	

	/*Wav firstWav;
	//firstWav.readFile("yes-8-bit-mono.wav");
	firstWav.readFile("z.wav");
	firstWav.printMeta();
	//firstWav.writeFile("z.wav");
	firstWav.writeFile("zz.wav");*/

}

std::vector<std::string> getWavFiles(char* directory) {
	DIR *dir; struct dirent *diread;
    	std::vector<std::string> files;
	std::vector<std::string> rf;


	if ((dir = opendir(directory)) != nullptr) {
        	while ((diread = readdir(dir)) != nullptr) {
            		files.push_back(std::string(diread->d_name));
		}
        } else {
        	std::cout << "failed to open files" << std::endl;
        	return files;
    	}
	
	for (std::string file : files) {
		if(file.substr(file.length()-1) == "v" && file.substr(file.length()-3) == "wav") {
			rf.push_back(file);
		}
	}
	return rf;
}

	


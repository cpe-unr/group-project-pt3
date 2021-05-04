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
#include "echo.h"
#include "noisegate.h"
#include "normalization.h"
#include "Processor.h"

std::vector<std::string> getWavFiles(char* directory);

int pickFromList(std::vector<std::string> list);

std::vector<Processor*> getProcessorsToBeApplied();

std::string getNF();


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
		bool exit = false;
		while(!exit){
			ui.applyLabel("------------------------");
			ui.applyLabel("[1] view list of files");
			ui.applyLabel("[2] view metadata");
			ui.applyLabel("[3] apply Processing");
			ui.applyLabel("[4] export to CSV");
			ui.applyLabel("[5] exit");
			int menuAction = ui.getIntMatch("Pick an option. [1-5]", 1, 5);
			if(menuAction == 1) {
				ui.applyLabel("Imported Files are: " + lof);
			} else if(menuAction == 2) {
				ui.applyLabel("Please pick a file");
				int pick = pickFromList(filePaths);
				ui.applyLabel("Printing the metadata for: " + filePaths.at(pick));
				wavs.at(pick)->printMeta();
			} else if(menuAction == 3) {
				ui.applyLabel("Please pick a file");
				int pick = pickFromList(filePaths);
				ui.applyLabel("Please pick what processors you would like to perform");
				std::vector<Processor*> toApply = getProcessorsToBeApplied();
				Wav* tempWav = wavs.at(pick);
				if(tempWav->getBitDepth() == 8){
					if(tempWav->getChannel() == 1) {
						//8 bit mono
						for(Processor* p : toApply){
							p->processBuffer8M(tempWav->getBuffer(), tempWav->getBufferSize());
						}
					} else {
						//8 bit stereo
						for(Processor* p : toApply){
							p->processBuffer8S(tempWav->getBuffer(), tempWav->getBufferSize());
						}
					}
				}else {
					if(tempWav->getChannel() == 1) {
						//16 bit mono
						for(Processor* p : toApply){
							p->processBuffer16M(tempWav->getBuffer2(), tempWav->getBufferSize());
						}
					} else {
						//16 bit stereo
						for(Processor* p : toApply){
							p->processBuffer16S(tempWav->getBuffer2(), tempWav->getBufferSize());
						}
					}
				}
				ui.applyLabel("Applied all of the processors");
				std::string nf = getNF();
				tempWav->writeFile(nf);
				ui.applyLabel("Wrote WAV data to: " + nf);
			} else if(menuAction == 4) {
				std::string csv = "filename, audio Format, channels, sample Rate, bit depth, metaData\n";
				for(int i = 0; i < filePaths.size(); i++) {
					csv += filePaths[i] + ",";
					csv += wavs[i]->csvOutput();
					csv += "\n";
				}
				std::ofstream csvFile;
				csvFile.open("WAV_information.csv");
				csvFile << csv << std::endl;
				csvFile.close();
				ui.applyLabel("Data written to: WAV_information.csv");
			} else {
				//option 5
				exit = true;
				ui.applyLabel("GoodBye");
			}

		}


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

int pickFromList(std::vector<std::string> list){
	ui ui;
	for(int i = 0; i < list.size(); i++) {
		std::string s = "[" + std::to_string(i+1) + "] ";
		ui.applyLabel(s + list.at(i));
	}
	return (ui.getIntMatch("Please pick an option: [1-" + std::to_string(list.size()) + "]", 1, list.size())-1);
}	

std::vector<Processor*> getProcessorsToBeApplied() {
	ui ui;
	std::vector<Processor*> currentList;
	std::string list;
	while(true) {
		ui.applyLabel("------------------------");
		ui.applyLabel(list);
		int resp = pickFromList({"Echo","Normalization","NoiseGate","Apply my choices"});
		if(resp == 0){
			list += "Echo, ";
			currentList.push_back(new Echo(20000));
		} else if (resp == 1) {
			list += "Normalization, ";
			currentList.push_back(new Normalization<int>());
		} else if (resp == 2) {
			list += "Noise Gate, ";
			currentList.push_back(new NoiseGate(10, 5000));
		} else {
			//apply choice
			return currentList;
		}
	}	
}

std::string getNF() {
	ui ui;
	std::string newName;
	bool isNew = false;

	while(!isNew) {
		newName = ui.getString("Please give us a new file name to save the processed wav data");
    		if (FILE *file = fopen(newName.c_str(), "r")) {
        		fclose(file);
        		isNew = false;
			ui.applyLabel("File already exists");
    		} else {
        		isNew = true;
    		}   
	}
	return newName;
}

#include "wav.h"



void Wav::readFile(std::string fileName) {
	std::ifstream audioFile;
    	audioFile.open(fileName, std::ios::binary | std::ios::in);

	if(audioFile.is_open()){
		//read the header
        	audioFile.read((char*)&wavHeader, sizeof(wavHeader));
		int remainingData = wavHeader.wav_size - 26;
		channel = wavHeader.num_channels;
		bitDepth = wavHeader.bit_depth;
		
		bool readData = false;
		bool readMeta = false;
        	while(remainingData > 0) {
			char nextHeader[4]; //stores the next Header. Could be DATA or LIST
			audioFile.read(nextHeader, sizeof(nextHeader)); //reads the next header
			remainingData -= sizeof(nextHeader); //removes the bytes from the count
			std::string str = "";  		//
			for(int i = 0; i < 4; i++){	// These lines just covert to string for if statement
				str += nextHeader[i];	//
		
			}
			
			if(str == "data" && !readData) {
				readData = true;
				//read main data
				int dataLength; //length of buffer
				audioFile.read((char*)&dataLength, sizeof(dataLength));
				remainingData -= sizeof(dataLength);
				bufferSize = dataLength;
				buffer = new unsigned char[dataLength]; //sets the buffer to correct size
				buffer2 = new signed char[dataLength];
				audioFile.read((char*)buffer, dataLength); //reads in audio data
				
				remainingData -= dataLength;
				//the remaining Data should now not include the Data portion.

			} else if(str == "LIST" && !readMeta) {
				readMeta = true;
				int metaLength; //length of meta
				audioFile.read((char*)&metaLength, sizeof(metaLength));//reads meta Length
				remainingData -= sizeof(metaLength);
				int metaRemaining = metaLength; // same as remaining Data just for meta
				char info[4]; //literally should just equal INFO
				audioFile.read(info, sizeof(info)); //not going to if check. Too lazy to
				remainingData -= sizeof(info);
				metaRemaining -= sizeof(info);
				//time to start the meta loop. Meta needs to have its own loop as there can 
				//be multiple chunks of metadata inside the giant "list" chunk
				while(metaRemaining > 5) {
					meta_data tempMD;
					audioFile.read((char*)&tempMD.metaName, 4);
					audioFile.read((char*)&tempMD.metaLength, 4);
					remainingData -= sizeof(tempMD);
					metaRemaining -= sizeof(tempMD);
					metaData.push_back(tempMD); //adds the meta name/size to vector

					char metaBuffer[tempMD.metaLength]; //char buffer for the actual data
					audioFile.read((char*)&metaBuffer, sizeof(metaBuffer));
					std::string metaString = "";  			//	
					for(int i = 0; i < sizeof(metaBuffer); i++){	//convert to string
						metaString += metaBuffer[i];		//	
					}
					remainingData -= tempMD.metaLength;
					metaRemaining -= tempMD.metaLength;
					metaContent.push_back(metaString); //adds content to seperate vector

				}
				//end of while loop
				//at this point, all metadata should be read

			} else {
				//There is a bunch of ID3 data at the bottom of your WAV files. This is me 
				//ignoring the problem. :) -josh
			}
		}//end of while loop
		//at this point all data should be fully read in and ready for use
        	audioFile.close();
    	}
}

void Wav::writeFile(std::string fileName) {
	std::ofstream audioFile;
	audioFile.open(fileName, std::ios::out |  std::ios::binary);
	audioFile.write((char*)&wavHeader, sizeof(wavHeader));


	//DATA portion
	audioFile << "data"; //Chunk name
    	audioFile << "SIZE"; // Data size (we can learn this after)
	int startOfData = audioFile.tellp();
	audioFile.write((char*)buffer, bufferSize);
	int endOfData = audioFile.tellp();


	//METADTA PORTION
	audioFile << "LIST";
	audioFile << "SIZE";
	int startOfMeta = audioFile.tellp();
	audioFile << "INFO";

	//assumes that all metadata is just ready to be written. Modification of metadata elsewhere should also update the size
	for(int i = 0; i < metaData.size(); i++) {
		audioFile.write(reinterpret_cast<char*>(&metaData[i]), sizeof(metaData[i]));
		audioFile << metaContent[i];
	}
	int endOfMeta = audioFile.tellp();
	int endOfFile = audioFile.tellp();
	
	audioFile.seekp(startOfMeta - 4);
	int metaL = endOfMeta - startOfMeta;
	audioFile.write(reinterpret_cast<char*>(&metaL), sizeof(metaL));
	
	audioFile.seekp(startOfData - 4);
	int dataL = endOfData - startOfData;
	audioFile.write(reinterpret_cast<char*>(&dataL), sizeof(dataL));

	audioFile.seekp(4, std::ios::beg);
	int fileL = endOfFile - 8;
	audioFile.write(reinterpret_cast<char*>(&fileL), sizeof(fileL));
	audioFile.close();
}

Wav::~Wav() {
    if(buffer != NULL)
        delete[] buffer;
}
void Wav::printMeta() {
	for(int i = 0; i < metaData.size(); i++) {
		std::cout << metaData[i].metaName << ": " << metaContent[i] <<  std::endl;
	} 
}

unsigned char *Wav::getBuffer(){
    return buffer;
}

signed char *Wav::getBuffer2(){
    return buffer2;
}

int Wav::getBufferSize() {
	return bufferSize;
}
int Wav::getChannel() {
	return channel;
}
short Wav::getBitDepth() {
	return bitDepth;
}

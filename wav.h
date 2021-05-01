#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

#ifndef wav_h
#define wav_h

struct wav_header { //SIZE OF = 36 //wav_size = 28 + full data + full meta
    	// RIFF
    	char riff_header[4]; // Contains "RIFF"
    	int wav_size; // Size of everything after
    	char wave_header[4]; // WAVE

    	// Format Header
    	char fmt_header[4]; //"fmt "
    	int fmt_chunk_size; // 16 "known variable"
    	short audio_format; // 1 for PCM
    	short num_channels; // 1 for mono, 2 for stereo
    	int sample_rate; //how many samples per second
    	int byte_rate; // Bytes per sec
   	short sample_alignment; // channels * byte depth
    	short bit_depth; // Number of bits per sample (byte depth = bit_depth /8)
};

struct meta_data {
	char metaName[4];
	int metaLength;
};

class Wav {
private:
	std::vector<meta_data> metaData;
	std::vector<std::string> metaContent;
	unsigned char* buffer = NULL;
	wav_header wavHeader;

	int bufferSize;
	int channel;
	short bitDepth; 
public:
	void readFile(std::string filename);
	void writeFile(std::string filename);
	virtual ~Wav();
	
	void printMeta();
	int getBufferSize();
	int getChannel();
	short getBitDepth();
	unsigned char *getBuffer();

};

#endif

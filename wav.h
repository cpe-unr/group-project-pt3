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
	signed char* buffer2 = NULL;
	wav_header wavHeader;

	int bufferSize;
	int channel;
	short bitDepth; 
public:
	/**
	*This is the method reading from a file.
	*@param filename - the name of the file we are looking into.
	*/
	void readFile(std::string filename);
	/**
	*This is the method used to write objects to a file.
	*@param filename - the name of the file we are looking into.
	*/
	void writeFile(std::string filename);
	/**
	*This method is an interface of a destructor used to delete an object.
	*/
	virtual ~Wav();
	

	/**
	*This method is used to print out the metadata.
	*/
	void printMeta();
	/**
	*This method is used to get the size of the buffer.
	*/
	int getBufferSize();
	/**
	*This method is used to find if there is one or two channels.
	*/
	int getChannel();
	/**
	*This method is to get the number of bits in a sample.
	*/
	short getBitDepth();
	/**
	*This method is used to get the buffer that is being used.
	*/
	unsigned char *getBuffer();
	/**
	*This method is used to get the buffer that is being used.
	*/
	signed char *getBuffer2();

};

#endif

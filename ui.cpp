#include "ui.h"


void ui::applyLabel(std::string label){
	std::cout << label << std::endl;
}

std::string ui::getString(std::string prompt){
	std::string input;
	applyLabel(prompt);
	std::cin >> input;
	return input;
}
int ui::getInt(std::string prompt) {
	int input;
	applyLabel(prompt);
	std::cin >> input;
	return input;
}

std::string ui::getStringMatch(std::string prompt, std::vector<std::string> match){
	std::string input;
	bool proper = false;
	while(!proper) {
		input = getString(prompt);
		for(std::string test : match){
			if(input == test){
				proper = true;
				break;
			}
		}
		if(!proper){
			applyLabel("input does not match any of the options");
		}
	}
	return input;
}


int ui::getIntMatch(std::string prompt, int low, int high){
	int input;
	bool proper = false;
	while(!proper) {
		input = getInt(prompt);
		if(input >= low && input <= high){
			proper = true;
		} else {
			applyLabel("Input not within bounds");
		}
	}
	return input;
}

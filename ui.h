#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#ifndef ui_h
#define ui_h

class ui {
public:
	void applyLabel(std::string label);
	std::string getString(std::string prompt);
	int getInt(std::string prompt);

	std::string getStringMatch(std::string prompt, std::vector<std::string> match);
	int getIntMatch(std::string prompt, int low, int high);
};



#endif

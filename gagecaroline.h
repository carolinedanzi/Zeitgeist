#include "Trends.h"

class gagecaroline : public Trends {
public: 
	void increaseCount(std::string s, int amount);
	unsigned int getCount(std::string s);
	std::string getNthPopular(unsigned int n);
	unsigned int numEntries();
};
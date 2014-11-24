#include "Trends.h"
#include "hashTable.h"
#include <vector>

class gagecaroline : public Trends {
public: 
	void increaseCount(std::string s, int amount);
	unsigned int getCount(std::string s);
	std::string getNthPopular(unsigned int n);
	unsigned int numEntries();

private: 
	std::vector<std::string> popularList;
	HashTable<std::string, int> wordCount;
};
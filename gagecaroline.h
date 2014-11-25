#include "Trends.h"
#include "hashTable.h"
#include <vector>

class gagecaroline : public Trends {
public: 
	virtual void increaseCount(std::string s, int amount);
	virtual unsigned int getCount(std::string s);
	virtual std::string getNthPopular(unsigned int n);
	virtual unsigned int numEntries();	

private: 
	std::vector<std::pair<std::string, int>> countOrg;
	HashTable<std::string, int> stringOrg;
	void bubbleUp(unsigned int index);
};
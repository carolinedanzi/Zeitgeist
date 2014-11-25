#include "Trends.h"
#include "HashTable.h"
#include <vector>

class gagecaroline : public Trends {
public: 
	virtual void increaseCount(std::string s, unsigned int amount);
	virtual unsigned int getCount(std::string s);
	virtual std::string getNthPopular(unsigned int n);
	virtual unsigned int numEntries();	

private: 
	std::vector<std::pair<std::string, int>> countOrg;
	HashTable<std::string, int> stringOrg;
	void bubbleUp(unsigned int index);
	//unsigned long hash(std::string k);
};
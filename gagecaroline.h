#include "Trends.h"
#include "HashTable.h"
#include <vector>

/*
Originality Note: Written by Gage Laufenberg and Caroline Danzi
Uses Gage's Hash Table lab, with some modification
*/

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
};
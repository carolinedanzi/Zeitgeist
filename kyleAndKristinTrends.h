#include "Trends.h"
#include <unordered_map>
#include <vector>

class kyleAndKristinTrends : public Trends {
public:
	kyleAndKristinTrends();
	~kyleAndKristinTrends();
	
	virtual void increaseCount(std::string s, unsigned int amount);
	virtual unsigned int getCount(std::string s);
	virtual std::string getNthPopular(unsigned int n);
	virtual unsigned int numEntries();
	

protected:
	//int to track spot in vector
	unsigned int n;
	//vector to store common counting ints for ourMap and sortingArr
	std::vector<int> ints;
	//Vector to store string and count for 
	std::vector<std::pair<std::string, unsigned int>> sortingArr;
	std::unordered_map<std::string, unsigned int> ourMap; //created a hash table?
	bool isSorted;
	
};
#include "naiveTrends.h"

class smarterTrends : public naiveTrends {
public:
	smarterTrends() { isSorted = false; }
	virtual void increaseCount(std::string s, unsigned int amount);
	virtual std::string getNthPopular(unsigned int n);

protected:
	bool isSorted;
};
#include "gagecaroline.h"

void gagecaroline::increaseCount(std::string s, int amount){
	
}

unsigned int gagecaroline::getCount(std::string s){
	int index = stringOrg.find(s);
	return countOrg[index].second;
}

// The vector is organized by popularity, where the nth 
// most popular is located at index n. We just need to 
// return the first object in the pair, which is the word.
std::string gagecaroline::getNthPopular(unsigned int n){
	return countOrg[n].first;
}

// Returns the size of the hash table where all the words are stored
unsigned int gagecaroline::numEntries(){
	return stringOrg.size();
}
#include "gagecaroline.h"
#include "hashTable.h"

void gagecaroline::increaseCount(std::string s, int amount){
	

		// If the word has already been seen, update the count
	if (stringOrg.keyExists(s)){
		unsigned int i = stringOrg.calcIndex(s);
		// The new count will be the old plus the new amount
		int newCount = getCount(s) + amount;
		stringOrg.changeValue(s, newCount);
		unsigned int index = stringOrg.find(s);
		bubbleUp(index);
	}

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

unsigned int gagecaroline::bubbleUp(unsigned int index){
	std::pair<std::string, int> temp;
	unsigned int ret;
	
	if(countOrg[index] > countOrg[index-1]){
		temp = countOrg[index];
		countOrg[index] = countOrg[index-1];
		countOrg[index-1] = temp;
		
		ret = bubbleUp(index-1);
	}

	return ret;

}
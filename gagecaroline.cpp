#include "gagecaroline.h"
//#include "hashPrimes.h"

/**
* Written by Dr. Brinkman
* This is a hash function for strings, based on Horner's method. See
* http://en.wikipedia.org/wiki/Horner's_method
*/
unsigned long hash(std::string k){
	unsigned long m = hashPrimes[NUM_HASH_PRIMES - 2];
	unsigned long ret = 0;
	for (unsigned int i = 0; i<k.size(); i++){
		ret = (256 * ret + k[i]) % m;
	}
	return ret;
}

void gagecaroline::increaseCount(std::string s, unsigned int amount){
	// If the word has already been seen, update the count
	if (stringOrg.keyExists(s)){
		// Find the index in the popularity vector and
		// update the count that is stored there
		int indexInArray = stringOrg.find(s);
		countOrg[indexInArray].second += amount;
		bubbleUp(indexInArray);
	}
	// If the word has not yet been seen, add it to the
	// vector and the hash table and then bubble it up
	else{
		countOrg.push_back(std::make_pair(s, amount));
		int index = countOrg.size() - 1;
		stringOrg.add(s, index);
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

void gagecaroline::bubbleUp(unsigned int index){
	if (index == 0){
		return;
	}
		
	std::pair<std::string, int> temp;

	// If the count has exceeded the count of the previous
	// element, we need to swap them so the more popular
	// element is first in the vector
	if (countOrg[index].second > countOrg[index - 1].second){
		temp = countOrg[index];
		countOrg[index] = countOrg[index - 1];
		countOrg[index - 1] = temp;

		// After swapping the pairs in the popularity vector,
		// we need to make sure the hash table contains
		// the new index in the popularity vector
		stringOrg.changeValue(countOrg[index].first, index - 1);
		// Call bubbleUp on the same element, which has moved
		// to a lower index in the array
		bubbleUp(index - 1);
	}
	// After bubbling up, we need to make sure the index stored
	// in the hash table is correct
	stringOrg.changeValue(countOrg[index].first, index);
}
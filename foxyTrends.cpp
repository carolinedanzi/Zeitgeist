#include "Trends.h"
#include "foxyTrends.h"
#include <algorithm>
#include <iostream>

bool compareFunc(std::pair<std::string, unsigned int> i, std::pair<std::string, unsigned int> j);

void foxyTrends::increaseCount(std::string s, unsigned int amount){
	// check to see if key is already in
	if (wordStoreTable.find(s) == wordStoreTable.end()){
		// add the element into the hash table mapped to array
		std::pair<std::string, int> word(s, count);
		wordStoreTable.insert(word);

		// add element to hash table to keep track of count
		std::pair<std::string, int> word1(s, amount);
		countStoreTable.insert(word1);

		// add element to back of vector
		std::pair<std::string, int> p1(s, amount);
		sortedArray[count] = p1;

		// set the iterator of the hash pair to the end of the current vector size
		isSorted = false;
		count++;

	}
	else{
		int y = wordStoreTable.find(s)->second;
		sortedArray[y].second++;

		countStoreTable.find(s)->second++;
	}
}

unsigned int foxyTrends::getCount(std::string s){
	return countStoreTable.find(s)->second;

}

std::string foxyTrends::getNthPopular(unsigned int n){

	if (!isSorted){
		std::sort(sortedArray.begin(), sortedArray.end(), compareFunc);
		isSorted = true;
		resetIndices();
	}

	if (n <= numEntries()){
		return sortedArray[n].first;
	}

	//If they give bad input, return empty string.
	return "";
	return "end";
}

unsigned int foxyTrends::numEntries() {
	int x = sortedArray.size();
	return wordStoreTable.size();
}

// This helper method resets the indexes of the hash table that
// contains indexes of the words after the array has been sorted.
// Takes 0(n) time :(
void foxyTrends::resetIndices(){
	for (unsigned int i = 0; i < numEntries(); i++){
		int newIndex = i;
		std::string x = sortedArray[i].first;
		wordStoreTable.find(x)->second;
	}
}
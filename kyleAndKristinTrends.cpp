#include "kyleAndKristinTrends.h"

#include <algorithm>
#include <string>
#include <iostream>




bool isSorted;

kyleAndKristinTrends::kyleAndKristinTrends() {	
	n = 0;
	isSorted = false;
}

void kyleAndKristinTrends::increaseCount(std::string s, unsigned int amount){
	
	
	std::unordered_map<std::string, unsigned int>::iterator found = ourMap.find(s);

	//element does not exist
	if (found == ourMap.end()) { 
		
		ints.push_back(amount);
		std::pair<std::string, unsigned int> p = std::make_pair(s, n);
		ourMap.insert(p);
		sortingArr.push_back(p);
		n++;	
	}

	else { //element does exist so update the amount
		ints[found->second] += amount;		
	}
	isSorted = false;
}

unsigned int kyleAndKristinTrends::getCount(std::string s){
	//Check to see if word is present
	unsigned int a;
	try
	{
		a = ourMap.at(s);
	}
	catch (const std::out_of_range s)
	{
		return 0;
		
	}
	return ints[a];
	
}




std::string kyleAndKristinTrends::getNthPopular(unsigned int n){
	if (!isSorted){
		std::sort(sortingArr.begin(), sortingArr.end(), 
		[this](const std::pair<std::string, unsigned int> i, std::pair<std::string, unsigned int> j) 
		{
			isSorted = true;
			if (ints[i.second] == ints[j.second]){
			return (i.first < j.first);
		}

		return (ints[i.second] > ints[j.second]); });
		
	}
	if (n <= numEntries()){
		return sortingArr[n].first;
		
	}
	//If they give bad input, return empty string.
	return "";
	
	
}

unsigned int kyleAndKristinTrends::numEntries(){
	return ourMap.size(); //radical
}
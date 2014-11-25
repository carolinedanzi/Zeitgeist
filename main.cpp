/*****
 * Author   : brinkmwj
 * Date     : 2009-10-04
 * Sources  : All code is original
 * Purpose  : The purpose of this file is to do some VERY rudimentary timing of your increaseCount
 *            method. For the QUALITY measures I am also going to test getCount, so you might want
 *            to design some way to test out the running time of your getCount as well!
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include "hashPrimes.h"

//#include "naiveTrends.h"//You will need to change this to match your own class
//#include "smarterTrends.h"
#include "gagecaroline.h"
#include "utilities.h"

/**
 * This tests a simple (but unlikely) use case, which is to read in all the data, and then print out the data in sorted order
 * based on popularity.
 *
 * Compare your 28885.txt.out to 28885_txt.out, using diff,s to see if your code is producing correct output.
 */
double useCase_addAllThenGetInOrder(){
	Trends* tr = new gagecaroline(); //You will need to change this to match your own class! --->   WHY DOES THIS NOT WORK?!

	std::vector<std::string> wordlist = getWordList("data/28885.txt");

	//We only want to time how long addToTrends takes, so we get
	// the starting time, which is the clock time, in milliseconds
	double start = getTimeInMillis();
	//Now add all the words to the Trends data structure
	for (unsigned int i = 0; i < wordlist.size(); i++){
		tr->increaseCount(wordlist[i], 1);
	}
	//Now get the end time
	double end = getTimeInMillis();
	std::cout << "increaseCount time: " << (end - start) / wordlist.size() << " ms per word" << std::endl;

	//Now we will print out the complete results. This could be REALLY clow, if
	// your getNthPopular is not a little bit smart.
	std::string outfname = "data/28885.txt.out";
	std::ofstream out(outfname.c_str());

	out << "gagecaroline Trends output" << std::endl;

	start = getTimeInMillis();
	for (unsigned int i = 0; i < tr->numEntries(); i++){
		std::string s = tr->getNthPopular(i);
		out << tr->getCount(s) << ": " << s << std::endl;
	}
	out.close();
	end = getTimeInMillis();
	std::cout << "getNth followed by getCount, time: " << (end - start) / tr->numEntries() << " ms per entry" << std::endl;

	delete tr;

	return end - start;
}

void useCase_AddThenGetMostPopular(){
	Trends* trend = new gagecaroline();

	std::vector<std::string> wordList = getWordList("data/28885.txt");

	std::string outfname = "data/28885.txt.out";
	std::ofstream out(outfname.c_str());

	double start = getTimeInMillis();
	for (unsigned int i = 0; i < wordList.size(); i++){
		trend->increaseCount(wordList[i], 1);
		std::string mostPopular = trend->getNthPopular(0);
		out << "After " << i << " words " << mostPopular << "is most popular" << std::endl;
	}
	double end = getTimeInMillis();

	std::cout << "increaseCount followed immediately by getNthPopular: " << (end - start) / trend->numEntries() << " ms per entry" << std::endl;
}

std::string getTopN(unsigned int n){
	Trends* trends = new gagecaroline();

	std::vector<std::string> wordlist = getWordList("data/28885.txt");


	std::string s;

	for (unsigned int i = 0; i <= n; i++){
		s = s + ". " + trends->getNthPopular(i) + " /n";
	}

	return s;
}





/*
 * The only purpose of main() is to call processFile with increasingingly larger and larger
 * files. A larger file will give a more accurate sense of how fast addToTrends is, but at some
 * point it may take so long to do the getNthPopular, that we aren't willing to wait for it to finish.
 */
int main(){

	/* The data files are books from project Gutenberg. I have provided the inputs, as well as my outputs
	 * in the starter files */

	useCase_addAllThenGetInOrder();

	return 0;
}

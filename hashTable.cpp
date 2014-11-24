//You will need this so you can make a string to throw in
// remove
#include <string>
#include "hashTable.h"

/* 
* Written by Gage Laufenberg. Modified by Caroline Danzi.
*/

template <class Key, class T>
HashTable<Key, T>::HashTable(){
	numItems = 0;
	numRemoved = 0;
	numPrimes = 0;
	backingArraySize = hashPrimes[numPrimes];
	backingArray = new HashRecord[backingArraySize];
}

template <class Key, class T>
HashTable<Key, T>::~HashTable() {
	delete[] backingArray;
}

template <class Key, class T>
unsigned long HashTable<Key, T>::calcIndex(Key k){
	unsigned long i = hash(k) % backingArraySize;

	while (true){
		if (!backingArray[i].isDel && backingArray[i].k == k) return i;

		else if (!backingArray[i].isNull) i = (i + 1) % backingArraySize;

		else break;
	}

	return numItems; //returns numItems if index cannot be found
}

template <class Key, class T>
void HashTable<Key, T>::add(Key k, T x){

	if (!keyExists(k)){

		if ((numItems + numRemoved) >= backingArraySize / 2) grow();

		unsigned long i = hash(k) % backingArraySize;

		while (!backingArray[i].isNull && !backingArray[i].isDel) {
			i = (i + 1) % backingArraySize;
		}

		if (backingArray[i].isNull) numItems++;

		if (backingArray[i].isDel) numRemoved--;

		backingArray[i].k = k;
		backingArray[i].x = x;
		backingArray[i].isNull = false;
		backingArray[i].isDel = false;
	}
}

template <class Key, class T>
void HashTable<Key, T>::remove(Key k){
	unsigned long i = calcIndex(k);

	backingArray[i].isDel = true;

	numItems--;
	numRemoved++;

}

template <class Key, class T>
T HashTable<Key, T>::find(Key k){
	unsigned long i = calcIndex(k);

	if (!keyExists(k)) throw std::string("Key does not exist");

	return backingArray[i].x;

}

template <class Key, class T>
bool HashTable<Key, T>::keyExists(Key k){

	unsigned long i = calcIndex(k);

	if (i == numItems) return false;

	if (i < backingArraySize) return true;
}

template <class Key, class T>
unsigned long HashTable<Key, T>::size(){
	return numItems;
}

template <class Key, class T>
void HashTable<Key, T>::changeValue(Key k, T x){
	unsigned long index = calcIndex(k);
	backingArray[index].x = x;
}

template <class Key, class T>
void HashTable<Key, T>::grow(){

	numPrimes++;
	unsigned long tempArraySize = hashPrimes[numPrimes];
	HashRecord *tempArray = new HashRecord[tempArraySize];
	backingArraySize = tempArraySize;
	numRemoved = 0;

	for (unsigned int i = 0; i < hashPrimes[numPrimes - 1]; i++){
		if (!backingArray[i].isDel && !backingArray[i].isNull){

			int h = hash(backingArray[i].k) % backingArraySize;
			while (!tempArray[h].isNull) {
				h = (h + 1) % tempArraySize;
			}
			tempArray[h].isNull = false;
			tempArray[h].isDel = false;
			tempArray[h].k = backingArray[i].k;
			tempArray[h].x = backingArray[i].x;

		}
	}

	delete[] backingArray;
	//backingArraySize = tempArraySize;
	backingArray = tempArray;

}
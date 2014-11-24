#include "USet.h"

template <class Key, class T>
class HashTable : public USet <Key, T> {
private:
	class HashRecord {
	public:
		Key k;
		T x;

		//If the slot in the hash table is totally empty, set this to true.
		bool isNull;

		//If the slot used to have something in it, but doesn't now, set
		// isDel to true, and isNull to false. isNull is only for slots
		// that have never been used
		bool isDel;

		HashRecord() { isNull = true; isDel = false; };
	};

public:
	//See USet.h for documentation of these methods
	virtual unsigned long size();
	virtual void add(Key k, T x);
	virtual void remove(Key k);
	virtual T find(Key k);
	virtual bool keyExists(Key k);
	virtual void changeValue(Key, T x);

	//Initialize all private member variables.
	HashTable();
	//Delete any dynamically allocated memory.
	virtual ~HashTable();

private:
	//A pointer to the array that holds the hash table data
	HashRecord* backingArray;

	//Whenever numItems + numRemoved >= backingArraySize/2, call
	// grow(). grow() should make a new backing array that is twice the
	// size of the old one, similar to what we did in the ArrayQueue
	// lab.
	//Note: You cannot just loop through the old array and copy it to the
	// new one! Since the backing array size has changed, each item will likely
	// map to a different slot in the array. You may just want to use add()
	// after initializing the new array.
	void grow();

	//This helper method should take a key, and return the index for that
	// item within the hash table. If the item already exists, return the
	// index of the existing item. If the item doesn't exist, return the index
	// where it OUGHT to be. This function can then be used as a helper method in
	// your other methods.
	unsigned long calcIndex(Key k);

	unsigned long numItems; //Number of items in the hash table

	//Note: Ordinarily, these OUGHT to be private. In this case I have
	// made them public for easy of testing.
public:
	unsigned long numRemoved; //Number of slots that have been removed but not re-used. Those that have isDel == true
	unsigned long numPrimes;
	unsigned long backingArraySize;
};
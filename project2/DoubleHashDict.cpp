#ifndef _DOUBLEHASHDICT_CPP
#define _DOUBLEHASHDICT_CPP

//DoubleHashDict.cpp
#include "DoubleHashDict.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

// An implementation of a dictionary ADT as hash table with double hashing
//

const int DoubleHashDict::primes[] = {53, 97, 193, 389, 769, 1543, 3079,
      6151, 12289, 24593, 49157, 98317, 196613, 393241, 786433, 1572869,
      3145739, 6291469, 12582917, 25165843, 50331653, 100663319,
      201326611, 402653189, 805306457, 1610612741, -1};
// List of good primes for hash table sizes from
// http://planetmath.org/goodhashtableprimes
// The -1 at the end is to guarantee an immediate crash if we run off
// the end of the array.
const int DoubleHashDict::notprimes[] = {100, 300, 1000, 3000, 10000,
      30000, 100000, 300000, 1000000, 3000000, 10000000, 30000000,
      100000000, 300000000, 1000000000, -1};
// List of bad sizes for the hash table and this hash function...


DoubleHashDict::DoubleHashDict() {
  size_index = 0;
  //size = primes[size_index];
  size = notprimes[size_index];
  table = new bucket[size](); // Parentheses force initialization to 0
  number = 0;

  // Initialize the array of counters for probe statistics
  probes_stats = new int[MAX_STATS]();
}

DoubleHashDict::~DoubleHashDict() {
  // Delete all table entries...
  for (int i=0; i<size; i++) {
    if (table[i].key!=NULL) {
      delete table[i].key;
      // Don't delete data here, to avoid double deletions.
    }
  }
  // Delete the table itself
  delete [] table;

  // It's not good style to put this into a destructor,
  // but it's convenient for this assignment...
  cout << "Probe Statistics for find():\n";
  for (int i=0; i<MAX_STATS-1; i++)
    cout << i << ": " << probes_stats[i] << endl;
  cout << "More: " << probes_stats[MAX_STATS-1] << endl;
  delete [] probes_stats;
}

// 221 Students:  DO NOT CHANGE THIS FUNCTION
// You need to call this function from your find (or from a helper function).
// Pass in the number of probes that you needed for that call to find.
// The number of probes should be the total number of buckets that you
// look at:  e.g., on an unsuccessful call to find, you should include
// the empty bucket at the end.
void DoubleHashDict::record_stats(int probes) {
  if (probes> MAX_STATS-1) probes = MAX_STATS-1;
  probes_stats[probes]++;
}



int DoubleHashDict::hash1(string keyID) {
  int h=0;
  for (int i=keyID.length()-1; i>=0; i--) {
    h = (keyID[i] + 31*h) % size;
  }
// 221 Students:  DO NOT CHANGE OR DELETE THE NEXT FEW LINES!!!
// We will use this code when marking to be able to watch what
// your program is doing, so if you change things, we'll mark it wrong.
#ifdef MARKING_TRACE
std::cout << "Hash 1:  " << keyID << " to " << h << std::endl;
#endif
// End of "DO NOT CHANGE" Block
  return h;
}

int DoubleHashDict::hash2(string keyID) {
  int h=0;
  for (int i=keyID.length()-1; i>=0; i--) {
    h = (keyID[i] + 29*h) % size;
  }
  // Make sure second hash is never 0 or size
  h = h/2 + 1;

// 221 Students:  DO NOT CHANGE OR DELETE THE NEXT FEW LINES!!!
// We will use this code when marking to be able to watch what
// your program is doing, so if you change things, we'll mark it wrong.
#ifdef MARKING_TRACE
std::cout << "Hash 2:  " << keyID << " to " << h << std::endl;
#endif
// End of "DO NOT CHANGE" Block
  return h;
}

int DoubleHashDict::hash3(string keyID) {
  int h=0;
  for (int i=keyID.length()-1; i>=0; i--) {
    h = (keyID[i] + 29*h) % size;
  }
  // Make sure second hash is never 0 or size
  h = h/2 + 1;

  while ((h%2==0) || (h%3==0) || (h%5==0)) h++;

// 221 Students:  DO NOT CHANGE OR DELETE THE NEXT FEW LINES!!!
// We will use this code when marking to be able to watch what
// your program is doing, so if you change things, we'll mark it wrong.
#ifdef MARKING_TRACE
std::cout << "Hash 3:  " << keyID << " to " << h << std::endl;
#endif
// End of "DO NOT CHANGE" Block
  return h;
}

void DoubleHashDict::rehash() {
// 221 Students:  DO NOT CHANGE OR DELETE THE NEXT FEW LINES!!!
// And leave this at the beginning of the rehash() function.
// We will use this code when marking to be able to watch what
// your program is doing, so if you change things, we'll mark it wrong.
#ifdef MARKING_TRACE
std::cout << "*** REHASHING " << size;
#endif
	// End of "DO NOT CHANGE" Block


	// TODO:  Your code goes here...

	// Keep a pointer to the old table.
	bucket *oldTable = table;
	int oldSize = size;
	// Get a bigger table
	size = primes[++size_index];
	table = new bucket[size]();
	// Rehash all the data over
	for (int count = 0; count < oldSize; count++){
		if (oldTable[count].key != NULL){
			add(oldTable[count].key, oldTable[count].data);
			number--;
		}
	}
	// No need to delete the data, as all copied into new table.
	delete[] oldTable;

	// 221 Students:  DO NOT CHANGE OR DELETE THE NEXT FEW LINES!!!
	// And leave this at the end of the rehash() function.
	// We will use this code when marking to be able to watch what
	// your program is doing, so if you change things, we'll mark it wrong.
#ifdef MARKING_TRACE
std::cout << " to " << size << " ***\n";
#endif
	// End of "DO NOT CHANGE" Block
}

bool DoubleHashDict::find(MazeState *key, MazeState *&pred) {
	// Returns true iff the key is found.
	// Returns the associated value in pred

	// TODO:  Your code goes here...
	int position = 0;
	if (key == NULL) {
		record_stats(++position);
		pred = NULL;
		return false;
	}
	string keyID = key->getUniqId();
	int targetKey;
	while (position < size) {
		targetKey = (hash1(keyID) + position*(hash2(keyID))) % size;
		if (table[targetKey].key == NULL) {
			record_stats(++position);
			pred = NULL;
			return false;
		}
		if ((table[targetKey].key->getUniqId()).compare(keyID) == 0) {
			record_stats(++position);
			pred = table[targetKey].data;
			return true;
		}
		else position++;
	}
	record_stats(++position);
	pred = NULL;
	return false;
}

// You may assume that no duplicate MazeState is ever added.
void DoubleHashDict::add(MazeState *key, MazeState *pred) {

	// Rehash if adding one more element pushes load factor over 3/4
	if (4 * (number + 1) > 3 * size) rehash();

	// TODO:  Your code goes here...

	string keyId = key->getUniqId();
	int hashKey = hash1(key->getUniqId());
	int position = 0;
	int targetkey;
	while (position < size) {
		targetkey = (hashKey + position*(hash2(keyId))) % size;
		if (table[targetkey].key == NULL) {
			//there is space here. Set the key, and data to the ones we have.
			table[targetkey].key = key;
			table[targetkey].data = pred;
			++number;
			return;
		}
		//Else it was not empty. Thus because this is linear, just increse f(i) by 1.
		else position++;
	}
}

#endif 

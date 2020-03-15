#pragma once
#include "HashTable.h"

HashTable::HashTable(int n) {

	//initially, populate hashtable with 0s
	N = n;
	while (n--) ht[n] = 0;
}



void HashTable::insertWithoutCollision(int n) {

	ht[h(n) % N] = n;
}

void HashTable::deleteWithoutCollision(int n) {
	int i = h(n) % N;
	if (ht[i] == n) ht[i] = -1;
}

bool HashTable::existWithoutCollision(int n) {
	return ht[h(n) % N] == n;
}

// assume >0 empty bucket
void HashTable::insertWithCollision(int n) {
	int i = h(n) % N;
	while (ht[i] > 0) {
		if (ht[i] == n) return;
		if (++i == N) i = 0;
	}
	ht[i] = n;
}

//n does not necasarrily exist in the hash table
void HashTable::deleteWithCollision(int n) {
	int i = h(n) % N;
	while (ht[i] != 0) {
		if (ht[i] == n) {
			ht[i] = -1;
			return;
		}
		if (++i == N) i = 0;
	}
}

bool HashTable::existWithCollision(int n) {
	int i = h(n) % N;
	while (ht[i] != 0) {
		if (ht[i] == n) return true;
		if (++i == N) i = 0;
	}
	return false;
}

void HashTable::printHashTable() {
	
	cout << "Current hash table: " << endl;
	for (int i = 0; i < N; i++) {
		cout << ht[i] << " ";
	}
	cout << endl;
}

/*
This is not a good hash function, since the numbers will be clustered together. 
For example, numbers under 100 will all only have hash values of less than 20.
This causes non-uniform hashing.

*/
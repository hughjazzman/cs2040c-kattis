int h(int x) {
	int ans = 0;
	while (x > 0) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

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
		if (i == h(n) % N) return; // only goes here after 1 round
	}
}

bool HashTable::existWithCollision(int n) {
	int i = h(n) % N;
	while (ht[i] != 0) {
		if (ht[i] == n) return true;
		if (++i == N) i = 0;
		if (i == h(n) % N) return false; // only goes here after 1 round
	}
	return false;
}

/*
This is a good hash function.

Firstly, it is very quick to compute, taking O(log n) time since it is only summing up the digits.

Secondly, across huge range of numbers, it will spread across the entire hash table. 
Of course, it will depend on your range of numbers and size of hash table used as well. 
Numbers from 1 to 1000000 will have hash values from 1 to 54.
*/
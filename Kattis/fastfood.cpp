#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <istream>

#define MAXSTI 30
#define MAXPRI 10
#define FOR(i, N) for(int i = 0; i < N; i++)

using namespace std;

void scanPrize(int stickType[], int prizeAmt[], int n) {
	int k, kt;
	// For each prize
	FOR(i, n) {
		cin >> k;
		// For each sticker
		FOR(j, k) {
			cin >> kt; kt--;
			stickType[kt] = i;
		}
		cin >> prizeAmt[i];
	}
}

void getTotal() {
	int n, m, total = 0, maxPossible = 0, currType, currPrize;
	int stickType[MAXSTI] = { 0 }, prizeAmt[MAXPRI] = { 0 };
	int prizeNum[MAXPRI]; // max number of each prize
	cin >> n >> m;
	FOR(i, m) {
		stickType[i] = -1;
	}
	FOR(i, n) {
		prizeNum[i] = -1;
	}
	
	scanPrize(stickType, prizeAmt, n);
	
	// For each sticker
	FOR(i, m) {
		// Get number of stickers
		cin >> currType;
		currPrize = stickType[i];
		if (currPrize == -1) continue;
		// If not set or less stickers than needed before
		if (prizeNum[currPrize] == -1 || currType < prizeNum[currPrize])
			prizeNum[currPrize] = currType;
	}
	FOR(i, n) {
		if (prizeNum[i] == -1) 
			prizeNum[i] = 0;
		total += prizeAmt[i] * prizeNum[i];
	}
	cout << total << endl;
}


int main() {
	int n;
	cin >> n;
	FOR(i, n) {
		getTotal();

	}
	return 0;
}


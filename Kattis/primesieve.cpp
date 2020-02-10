#include <iostream>

using namespace std;
using ll = long long;

int isComposite(int arr[], int n) {
	if (n == 2) return 0;
	if (n == 1 || n%2 == 0) return 1;

	n--; // 0-base indexing
	// n >> 1: divide by 2
	// & 31: modulo 31
	// 1 <<: bit shifts to be able to & with 32-bit int from array
	return arr[n / 64] & (1 << ((n >> 1) & 31));
}

void makeComposite(int arr[], int d, int n) {
	int i, j, k;
	k = d << 1;
	for (i = d * d; i < n && i > 0; i += k) {
		if (i % 2 == 0) continue;
		
		j = i - 1;
		arr[j / 64] |= (1 << ((j >> 1) & 31));

	}
}

void primesieve() {
	int n=0, q=0, count = 1, num = 0, i = 0, arrSize = 0;
	ll p2;
	int* arr = NULL;
	cin >> n >> q; 
	arrSize = n / 64; arrSize++;
	arr = new int[arrSize];
	for (i = 0; i < arrSize; i++)
		arr[i] = 0;

	for (i = 3; i <= n; i+=2) {
		if (!isComposite(arr, i)) {
			count++;

			// check from p^2 onwards, ll is necessary due to overflow
			p2 = (ll)i * (ll)i;
			if (p2<= n)
				makeComposite(arr, i, n);
		}
	}
	cout << count << '\n';
	
	for (i = 0; i < q; i++) {
		cin >> num;
		cout << !isComposite(arr, num) << '\n';
	}
	delete[] arr;
	arr = NULL;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    primesieve();
    return 0;
}
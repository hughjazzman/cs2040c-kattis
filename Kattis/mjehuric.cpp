#include <iostream>
#include <algorithm>

using namespace std;

void mje() {
	int arr[5] = {};
	bool b;
	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	
	for (int i = 0; i < 5; i++) {
		b = false;
		for (int j = 0; j < 4 - i; j++) {
			if (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j + 1]);
				b = true;
				for (int k : arr)
					cout << k << ' ';
				cout << '\n';
			}
		}
		if (!b) break;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    mje();
    return 0;
}
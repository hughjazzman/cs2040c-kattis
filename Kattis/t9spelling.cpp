#include <string>
#include <iostream>

using namespace std;

void output(char& c, int *idx, int arr[]) {
	int n = 0, curr_idx = 0;
	if (c == ' ') {
		curr_idx = -1;
	} else {
		n = c - 'a';
		for (int i = 0; i < 10; i++) {
			if (n >= arr[i])
				curr_idx = i;
			else {
				n -= arr[i - 1];
				break;
			}
				
		}
	}
	if (curr_idx == *idx)
		cout << ' ';
	*idx = curr_idx;
	for (int j=0; j < n + 1; j++) {
		cout << curr_idx + 1;
	}
	
}

void t9() {
	int arr[] = { 0, 0, 3, 6, 9, 12, 15, 19, 22, 26};
	int n, idx = -9;
	string s;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		cout << "Case #" << i + 1 << ": ";
		for (auto& c : s)
			output(c, &idx, arr);
		cout << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	t9();

	return 0;
}
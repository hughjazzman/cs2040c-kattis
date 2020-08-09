#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <climits>


using namespace std;

void stat() {
	string s;
	
	int c = 1, n, i, hi, low, rng = 0;
	while (getline(cin, s)) {
		istringstream iss(s);
		hi = INT_MIN; low = INT_MAX;
		
		iss >> n;

		while (iss >> i) {
			if (i > hi)
				hi = i;
			if (i < low)
				low = i;
			
			rng = hi - low;
		}
		cout << "Case " << c++ << ": " << low << ' ' << hi << ' ' << rng << '\n';
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    stat();
    return 0;
}
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_set>


using namespace std;

void fox() {
	int t;
	string s, r, a, g, snd;
	unordered_set<string> st;
	vector<string> v;
	cin >> t;
	cin.ignore();
	while (t--) {
		getline(cin, s);
		istringstream iss(s);
		while (iss >> r) { 
			v.push_back(r);
			if (!st.count(r))
				st.insert(r);
		}
		
		while (cin >> a >> g >> snd) {
			if (a == "what") {
				cin.ignore();
				getline(cin, s);
				break;
			}
			st.erase(snd);
		}

		for (string& x : v) {
			if (st.count(x))
				cout << x << ' ';
		}
		cout << '\n';

		v.clear();
		st.clear();
	}

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fox();
    return 0;
}
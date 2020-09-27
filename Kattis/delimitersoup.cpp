#include <iostream>
#include <stack>
#include <string>

using namespace std;


void des() {
	stack<char> st;
	int L, i = -1;
	string s;
	cin >> L; cin.ignore();
	getline(cin, s);

	for (char &c : s) {
		++i;
		if (c == ' ') continue;
		if (c == '[' || c == '(' || c == '{') {
			st.push(c);
			continue;
		}
		if (!st.empty()) {
			char tp = st.top();
			if (c == ']' && tp == '[' ||
				c == ')' && tp == '(' ||
				c == '}' && tp == '{') {
				st.pop();
				continue;
			}
		}
		
		cout << c << ' ' << i;
		return;

	}
	cout << "ok so far\n";
	
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    des();
    return 0;
}
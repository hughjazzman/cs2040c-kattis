#include <iostream>
#include <deque>
#include <string>

using namespace std;

void bsp() {
	deque<char> st;
	string s;
	cin >> s;
	for (char& c : s) {
		if (c == '<')
			st.pop_back();
		else
			st.push_back(c);
	}

	for (char& c : st)
		cout << c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bsp();
    return 0;
}
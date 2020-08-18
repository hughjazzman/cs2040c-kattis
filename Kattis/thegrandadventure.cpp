#include <iostream>
#include <stack>

using namespace std;

void gradv() {
	int n;
	char c;
	cin >> n; cin.ignore();
	while (n--) {
		stack<char> st;
		while (cin.get(c)) {
			if (c == '\n') break;
			if (c == '.') continue;
			if (c == '$' || c == '|' || c == '*')
				st.push(c);
			else if (st.empty() || 
				c == 't' && st.top() != '|' ||
				c == 'j' && st.top() != '*' ||
				c == 'b' && st.top() != '$') {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				st.push('.');
				break;
			}
			else
				st.pop();
		}
		if (st.empty()) cout << "YES";
		else cout << "NO";
		cout << '\n';
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    gradv();
    return 0;
}
#include <iostream>
#include <string>
#include <list>
#include <stack>

using namespace std;

void empty_stack(list<char> &res, stack<char> &stk) {
	while (!stk.empty()) {
		res.push_front(stk.top());
		stk.pop();
	}
}

void special(list<char> &res, stack<char> &stk, char &c, int *idx) {
	if (c == '<') {
		if (*idx == 0 && !stk.empty())
			stk.pop();
		else if (*idx == -1 && !res.empty())
			res.pop_back();
	}
	// when pressing home, empty stack
	else if (c == '[') {
		empty_stack(res, stk);
		*idx = 0;
	}
	else if (c == ']')
		*idx = -1;
	// after pressing end
	else if (*idx == -1) {
		empty_stack(res, stk);
		res.push_back(c);
	}
	// add to stack
	else
		stk.push(c);
}

void decode() {
	string s;
	list<char> res;
	stack<char> stk;
	char c;
	int idx = -1;
	getline(cin, s);

	for (auto& c: s) {
		special(res, stk, c, &idx);
	}
	empty_stack(res, stk);
	for (auto& c : res)
		cout << c;
	cout << '\n';
}

void sim() {
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		decode();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sim();

	return 0;
}
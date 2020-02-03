#include <iostream>
#include <deque>
#include <string>

using namespace std;

void balance(deque <int> &q1, deque <int> &q2) {
	int s1 = q1.size(), s2 = q2.size();
	if (s1 - s2 > 1) {
		q2.push_front(q1.back());
		q1.pop_back();
	}
	else if (s2 - s1 > 0) {
		q1.push_back(q2.front());
		q2.pop_front();
	}
}

void get(deque <int> &q1, deque <int> &q2, int n) {
	if (n < q1.size())
		cout << q1[n];
	else
		cout << q2[n - q1.size()];
	cout << endl;
}

void execComd(deque <int> &q1, deque <int> &q2, string com, int num) {
	if (com == "push_back")
		q2.push_back(num);
	else if (com == "push_front")
		q1.push_front(num);
	else if (com == "push_middle")
		q2.push_front(num);
	else if (com == "get")
		get(q1, q2, num);
	balance(q1, q2);
}

void teque() {
	int n, num;
	string com;
	deque <int> q1, q2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> com >> num;
		execComd(q1, q2, com, num);
	}
}

int main() {
    teque();
    return 0;
}
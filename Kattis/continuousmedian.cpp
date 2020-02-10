#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;


void insert(priority_queue <int> &s, priority_queue<int, vector<int>, greater<int>> &b, int num, int med) {
	int ssz = s.size(), bsz = b.size();
	if (ssz == 0) {
		s.push(num);
		return;
	}

	// Equal heaps
	if (ssz == bsz) {
		if (num > med)
			b.push(num);
		else
			s.push(num);
	}
	// Small heap is 1 less than big heap
	else if (ssz < bsz) {
		if (num > med) {
			// If num is bigger than smallest in big heap, move said smallest to small

			s.push(b.top());
			b.pop();

			b.push(num);
		}
		else
			s.push(num);
	}
	// Big heap is 1 less than small heap
	else {
		if (num >= med)
			b.push(num);
		else {
			b.push(s.top());
			s.pop();

			s.push(num); 
		}
	}
}

int getMed(priority_queue <int> &s, priority_queue <int, vector<int>, greater<int>> &b) {
	int ssz = s.size(), bsz = b.size();
	if (ssz + bsz == 1) 
		return s.top();
	if (ssz == bsz)
		return (s.top() + b.top()) >> 1;
	if (ssz > bsz)
		return s.top();
	else
		return b.top();

}

void compMed() {
	int N, num, med = 0;
	ll total = 0;
	priority_queue <int> small;
	priority_queue <int, vector<int>, greater<int>> big;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		insert(small, big, num, med);
		med = getMed(small, big);
		total += med;
	}
	cout << total << '\n';
}


void conMed() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		compMed();
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    conMed();
    return 0;
}
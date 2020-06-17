#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<string, ll> sp;
typedef pair<ll, sp> tsp;


void receive(priority_queue<sp, vector<sp>, greater<sp>>& pile, priority_queue<tsp, vector<tsp>, greater<tsp>>& gift, ll t) {
	while (!gift.empty() && t >= gift.top().first) {
		sp book = gift.top().second;
		gift.pop();
		pile.push(book);
	}
}

void jane() {
	ll n, m, t, k, p;
	string s, book;
	string delimiter = "\"";
	priority_queue<sp, vector<sp>, greater<sp>> pile;
	priority_queue<tsp,vector<tsp>, greater<tsp>> gift;
	cin >> n >> m >> k;
	string jane = "Jane Eyre";
	pile.push(make_pair(jane, k));
	cin.ignore();
	while (n--) {
		getline(cin, s);
		s.erase(0,1);
		book = s.substr(0, s.find(delimiter));
		s.erase(0, s.find(delimiter) + delimiter.length() + 1);
		p = stoi(s);

		pile.push(make_pair(book, p));
	}

	while (m--) {
		cin >> t;
		cin.ignore();
		getline(cin, s);
		s.erase(0, 1);
		book = s.substr(0, s.find(delimiter));
		s.erase(0, s.find(delimiter) + delimiter.length() + 1);
		p = stoi(s);

		gift.push(make_pair(t, make_pair(book, p)));

	}


	ll st = 0;
	receive(pile, gift, st);
	
	string next_book = pile.top().first;

	while (next_book != jane) {
		ll time = pile.top().second;
		pile.pop();
		
		st += time;
		receive(pile, gift, st);
		next_book = pile.top().first;
	}

	cout << st + k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    jane();
    return 0;
}
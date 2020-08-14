#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define FOR(i,k) for(int i=0;i<k;i++)

void forward(int dir, int *x, int *y) {
	switch (dir) {
	case 0: //U
		(*x)--;
		break;
	case 1: //R
		(*y)++;
		break;
	case 2: //D
		(*x)++;
		break;
	case 3: //L
		(*y)--;
		break;
	}
}

int changeDir(int dir, char turn) {
	if (turn == 'R') {
		if (dir == 3)
			dir = 0;
		else
			dir++;
	}
	else {
		if (dir == 0)
			dir = 3;
		else
			dir--;
	}
	return dir;
}



void turtm() {
	string s;
	int dir = 1; //R
	int x = 7, y = 0, cx, cy;
	vector<string> g;
	FOR(i, 8) {
		cin >> s;
		g.push_back(s);
	}
	cin >> s;
	for (char c : s) {
		switch (c) {
		case 'F':
			forward(dir, &x, &y);
			if (x < 0 || x > 7 || y < 0 || y > 7) {
				cout << "Bug!";
				return;
			}
			else if (g[x][y] == 'C' || g[x][y] == 'I') {
				cout << "Bug!";
				return;
			}
			break;
		case 'L':
		case 'R':
			dir = changeDir(dir, c);
			break;
		case 'X':
			cx = x; cy = y;
			forward(dir, &cx, &cy);
			if (cx < 0 || cx > 7 || cy < 0 || cy > 7) {
				cout << "Bug!";
				return;
			}
			else if (g[cx][cy] != 'I') {
				cout << "Bug!";
				return;
			}
			g[cx][cy] = '.';
			break;
			
		}
	}
	if (g[x][y] == 'D')
		cout << "Diamond!";
	else
		cout << "Bug!";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    turtm();
    return 0;
}
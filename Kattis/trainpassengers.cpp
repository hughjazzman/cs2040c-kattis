#include <iostream>

using namespace std;

bool check(int C, int *curr) {
	int left, ent, stay, oldCurr = *curr;
	cin >> left >> ent >> stay;
	
	*curr -= left;
	*curr += ent;
	// If num left is more than inside
	// If enter when full capacity
	// If stay when not full capacity
	return !(left > oldCurr || ent > C - (oldCurr - left) || (stay && C + left - ent - oldCurr));
}

void train() {
	int C, n, curr = 0;
	bool valid = 1;
	cin >> C >> n;
	while (n-- && valid) {
		valid = check(C, &curr);
	}
	if (valid && !curr)
		cout << "possible";
	else
		cout << "impossible";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    train();
    return 0;
}
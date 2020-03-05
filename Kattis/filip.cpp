#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void filip() {
	string n, m, res;
	cin >> n >> m;
	for (int i = 2; i >= 0; i--) {
		if (n[i] > m[i])
			res = n;
		else if (n[i] < m[i])
			res = m;
		if (n[i] != m[i]) break;
	}
	reverse(res.begin(), res.end());
	cout << res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	filip();

	return 0;
}
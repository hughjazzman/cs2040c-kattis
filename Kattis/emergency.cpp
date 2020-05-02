// CS2040/C Past Finals H

#include <iostream>

using namespace std;

typedef long long ll;

void emer() {
	ll n, k;
	cin >> n >> k;
	if (--n < 2 * k)
		cout << n;
	else
		cout << k + 1 + n % k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    emer();
    return 0;
}
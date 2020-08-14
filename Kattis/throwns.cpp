#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void thr() {
	int n, k, m, i = 0, e = 0;
	cin >> n >> k;
    vector<int> v(k, 0);
	while (k--) {
        
        cin >> m;
        if (cin.fail())
        {
            // clear error state
            cin.clear();
            // discard 'bad' character(s)
            cin.ignore(5, ' ');
            cin >> m;
            i -= m;
            e = v[i];
        }
        else {
            i++;
            v[i] = (e + m) % n;
            e = v[i];
        }
        
	}
    if (e < 0)
        cout << n + e;
    else
        cout << e;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    thr();
    return 0;
}
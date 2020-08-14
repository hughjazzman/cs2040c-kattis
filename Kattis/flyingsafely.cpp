#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int TC, n, m;

    cin >> TC;
    while (TC--) {
        cin >> n >> m; cin.ignore();
        cout << n - 1 << '\n';
        while (m--)
            cin.ignore(20, '\n');
    }

    return 0;
}
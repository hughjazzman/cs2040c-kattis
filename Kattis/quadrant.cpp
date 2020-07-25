#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x, y, r;
    cin >> x >> y;
    r = x > 0 ? (y > 0 ? 1 : 4) : (y > 0 ? 2 : 3);
    cout << r;

    return 0;
}
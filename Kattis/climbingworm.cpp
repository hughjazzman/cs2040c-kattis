#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b, h, q, r;
    cin >> a >> b >> h;
    
    if (h <= a) {
        cout << 1;
        return 0;
    }

    q = (h - a) / (a - b);
    r = (h - a) % (a - b);
    q++;

    if (r)
        cout << q + 1;
    else
        cout << q;

    return 0;
}
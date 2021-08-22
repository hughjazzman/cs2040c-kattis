#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

void reduce(ll *n, int k) {
    int m = (*n) % k;
    *n /= k;
    if (m > 1)
        (*n)++;
} 

void chew() {
    ll N, K, Q, x, y, st;
    cin >> N >> K >> Q;
    while (Q--) {
        cin >> x >> y;
        if (K == 1) {
            cout << abs(x - y) << '\n';
            continue;
        }
        st = 0;
        while (x != y) {
            if (x > y)
                reduce(&x, K);
            else
                reduce(&y, K);
            st++;
        }
        cout << st << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    chew();
    return 0;
}
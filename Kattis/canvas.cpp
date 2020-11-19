#include <iostream>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

typedef long long ll;

void canv() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<ll> v(N);
        for (int i = 0; i < N; ++i) 
            cin >> v[i];
        priority_queue<ll, vector<ll>, greater<ll>> q(v.begin(), v.end());
        ll r = 0, cr = 0;
        while (q.size() > 1) {
            cr = 0;
            cr += q.top();
            q.pop();
            cr += q.top();
            q.pop();
            q.push(cr);
            r += cr;
        }
        cout << r << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    canv();
    return 0;
}
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N, P, K;
    cin >> N >> P;
    vector<ll> T(N);
    for (int i = 0; i < N; ++i)
        cin >> T[i];
    while (--N)
        cin >> K;
    cout << accumulate(T.begin(), T.end(), 0LL) + (P - 1) * *max_element(T.begin(), T.end());
    return 0;
}
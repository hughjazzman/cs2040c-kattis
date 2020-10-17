#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;

void mc() {
    int C, N, M, ci, di, bi, tot, tmp;
    ll arr[51] = {0}, res[51] = {0};
    cin >> C >> N >> M;

    for (int i = 0; i < N; ++i) {
        bi = 0;
        cin >> ci;
        // count how many days it takes before limit is reached
        while ((ci << 1) <= C) {
            ci = ci << 1;
            bi++;
        }
        arr[bi]++;
    }

    tot = N - arr[0];

    for (int i = 1; i < 51; ++i) {
        tmp = arr[i];
        res[i] = (arr[i-1] << 1) + tot;
        arr[i] += (arr[i-1] << 1);
        tot -= tmp;
    }

    res[0] = N;

    while (M--) {
        cin >> di;
        cout << res[di] << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    mc();
    return 0;
}
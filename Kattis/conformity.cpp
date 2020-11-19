#include <iostream>
#include <algorithm>
#include <unordered_map>

#define SHIFT 9

using namespace std;

typedef long long ll;

void conf() {
    int n, m = 0, r = 0;
    ll h, arr[5];
    unordered_map<ll, int> mp;
    cin >> n;
    while (n--) {
        cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
        sort(arr, arr+5);
        h = 0;
        for (int i = 0; i < 5; ++i)
            h += arr[i] << (SHIFT*i);
        if (!mp.count(h))
            mp[h] = 0;
        mp[h]++;
        if (mp[h] < m) continue;
        if (mp[h] == m)
            r += mp[h];
        else {
            m = mp[h];
            r = m;
        }
        
    }
    cout << r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    conf();
    return 0;
}
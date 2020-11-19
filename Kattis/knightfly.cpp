#include <iostream>
#include <vector>
#include <utility>  
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

struct hash_pair {
   template <class T1, class T2>
   size_t operator()(const pair<T1, T2>& p) const{
      auto hash1 = hash<T1>{}(p.first);
      auto hash2 = hash<T2>{}(p.second);
      return hash1 ^ hash2;
   }
};

struct hash_ll {
    size_t operator()(const ii &p) const {
        ll res = (ll)p.first + (ll)2e9*(ll)p.second;
        return hash<ll>{}(res);
    }
};

void knf() {
    int N, sx, sy, tx, ty, X, Y;
    int dir[][3] = {{0,0,2},{0,0,3},{1,1,2},{1,1,3},{2,2,0},{2,2,1},{3,3,0},{3,3,1}};
    cin >> N >> sx >> sy >> tx >> ty;
    if (sx == tx && sy == ty) {
        cout << 0;
        return;
    }
    unordered_map<ii, int, hash_ll> mp;
    vector<ii> v(N), g(N); //vertex pairs, graph
    vector<vector<int>> nb(N, vector<int>(4, -1)); //neighbours, UDLR
    for (int i = 0; i < N; ++i) {
        cin >> X >> Y;
        v[i] = {X,Y};
        mp[{X,Y}] = i;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N - 1; ++i) {
        ii cv = v[i], nv = v[i+1];
        int cvi = mp[cv], nvi = mp[nv];
        if (cv.first != nv.first) continue;
        nb[cvi][0] = nvi; //set up
        nb[nvi][1] = cvi; //set down
    }
    stable_sort(v.begin(), v.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });
    for (int i = 0; i < N - 1; ++i) {
        ii cv = v[i], nv = v[i+1];
        int cvi = mp[cv], nvi = mp[nv];
        if (cv.second != nv.second) continue;
        nb[cvi][3] = nvi; //set right
        nb[nvi][2] = cvi; //set left
    }
    queue<int> q;
    vector<int> b(N, 0);
    int si = mp[{sx,sy}], ti = mp[{tx,ty}];
    q.push(si);
    b[si] = 1;
    while (!q.empty()) {
        int cv = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int nv = cv;
            for (int j = 0; j < 3; ++j) {
                nv = nb[nv][dir[i][j]];
                if (nv == -1) break;
            }
            if (nv == ti) {
                cout << b[cv];
                return;
            }
            if (nv == -1) continue;
            if (b[nv]) continue;
            b[nv] = b[cv] + 1;
            q.push(nv);
        }
    }
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    knf();
    return 0;
}
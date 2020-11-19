#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii, int> iii;

void cottr() {
    int N, D, C, ci, s, t;
    cin >> N >> D >> C;
    vector<iii> times(N); //start end times
    vector<int> infct(C); //initial infected
    vector<vector<int>> g(N); //graph
    queue<ii> q; //queue for BFS
    vector<bool> b(N,false);
    for (int i = 0; i < C; ++i) {
        cin >> ci; --ci;
        infct[i] = ci;
    }
        
    for (int i = 0; i < N; ++i) {
        cin >> s >> t;
        times[i] = {{s,t},i};
    }
    sort(times.begin(), times.end());
    for (int i = 0; i < N; ++i) {
        int cv = times[i].second;
        ii cvt = times[i].first;
        for (int j = i + 1; j < N; ++j) {
            int nv = times[j].second;
            ii nvt = times[j].first;
            if (cvt.second < nvt.first) break;
            g[cv].push_back(nv);
            g[nv].push_back(cv);
        }
    }
    for (int i : infct) {
        q.push({0,i});
        b[i] = true;
    }
        
    while (!q.empty()) {
        int cv = q.front().second, cd = q.front().first;
        q.pop();
        if (cd == D) continue;
        for (int i : g[cv]) {
            if (b[i]) continue;
            b[i] = true;
            q.push({cd+1,i});
            infct.push_back(i);
        }
    }
    sort(infct.begin(), infct.end());
    for (int i : infct)
        cout << i + 1 << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cottr();
    return 0;
}
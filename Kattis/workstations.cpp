#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;

void wst() {
    int n, m, a, s, k = 1, r = 0;
    priority_queue<int, vector<int>, greater<int>> q; //min heap
    cin >> n >> m;
    vector<ii> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> a >> s;
        v[i] = {a,a+s};
    }
    sort(v.begin(), v.end());
    int ce = v.begin()->second;
    q.push(ce);
    while (k < n) {
        int cs = v[k].first; // current next start
        int ce = q.top(); // current earliest end
        //keep adding to pq as long as next start
        // is earlier than earliest end
        while (cs < ce) {
            int ne = v[k].second; // add next end time
            q.push(ne);
            ++k;
            if (k == n) break;
            cs = v[k].first;
            ce = q.top();
        }
        if (k == n) break;
        q.pop();
        // if next start is too far skip
        if (ce + m < cs && !q.empty()) continue;
        // no need to unlock
        if (ce + m >= cs)
            ++r;
        q.push(v[k].second);
        ++k;
    }
    cout << r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    wst();
    return 0;
}
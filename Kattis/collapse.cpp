#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

void coll() {
    int N, T, K, S, V;
    queue<int> q; // queue to check collapsing
    
    cin >> N;
    vector<vector<ii>> g(N); // AL
    vector<int> thresh(N); // threshold values
    vector<int> inc(N, 0); // incoming goods
    vector<bool> b(N, false); // collapsed
    
    q.push(0);
    b[0] = true;
    
    for (int i = 0; i < N; ++i) {
        
        cin >> T >> K;
        thresh[i] = T;
        while (K--) {
            cin >> S >> V;
            --S;
            g[S].push_back({i,V});

            inc[i] += V;
        }
        // If under threshold add to queue
        if (inc[i] < T) {
            q.push(i);
            b[i] = true;
        }
    }

    while (!q.empty()) {
        int n = q.front();
        q.pop();
        N--;

        for (ii x : g[n]) {
            int nn = x.first, ng = x.second;
            if (b[nn]) continue; // collapsed already
            inc[nn] -= ng;
            if (inc[nn] >= thresh[nn]) continue;
            q.push(nn);
            b[nn] = true;
        }
    }

    cout << N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    coll();
    return 0;
}
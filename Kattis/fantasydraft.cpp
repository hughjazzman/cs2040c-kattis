#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <unordered_map>


using namespace std;

void fd() {
    int n, k, q, p;
    string s;
    unordered_map<string, int> mp;
    set<int> st;

    cin >> n >> k;
    
    vector<queue<string>> pref(n);
    vector<vector<string>> res(n, vector<string>(k));


    for (int i = 0; i < n; ++i) {
        cin >> q;
        for (int j = 0; j < q; ++j) {
            cin >> s;
            pref[i].push(s);
        }
    }


    
    cin >> p >> s;
    vector<string> rnk(p);
    rnk[0] = s;
    mp[s] = 0;
    st.insert(0);
    auto it = st.begin();

    for (int i = 1; i < p; ++i, ++it) {
        cin >> s;
        mp[s] = i;
        rnk[i] = s;
        st.insert(it, i);
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            string cur, t = "";
            while (!pref[j].empty()) {
                t = pref[j].front();
                pref[j].pop();
                if (mp.count(t))
                    break;
                else
                    t = "";
            }

            if (t.empty())
                it = st.begin();
            else
                it = st.find(mp[t]);
            
            
            res[j][i] = rnk[*it];
            st.erase(it);
            mp.erase(rnk[*it]);

        }
    }

    for (auto x : res) {
        for (string t : x) 
            cout << t << ' ';
        cout << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fd();
    return 0;
}
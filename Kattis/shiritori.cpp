#include <iostream>
#include <unordered_set>

using namespace std;

void shir() {
    int N;
    bool b = false;
    string s, pre;
    unordered_set<string> st;
    cin >> N >> pre;
    st.insert(pre);

    while (--N) {
        cin >> s;
        if (st.count(s) || s[0] != pre.back()) {
            int p = b ? 1 : 2;
            cout << "Player " << p << " lost";
            return;
        }
        st.insert(s);
        pre = s;
        b ^= true;
    }
    cout << "Fair Game";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    shir();
    return 0;
}
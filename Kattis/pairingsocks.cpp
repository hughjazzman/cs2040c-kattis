#include <iostream>
#include <stack>

using namespace std;

void psck() {
    int n, a, r = 0;
    stack<int> st;
    cin >> n;

    for (int i = 0; i < 2*n; ++i) {
        cin >> a;
        if (st.empty() || st.top() != a)
            st.push(a);
        else {
            ++r;
            st.pop();
        }
    }
    if (st.empty())
        cout << 2*r;
    else
        cout << "impossible";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    psck();
    return 0;
}
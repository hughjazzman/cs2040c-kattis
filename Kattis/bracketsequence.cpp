#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <numeric>

#define MOD 1000000007

using namespace std;

typedef long long ll;

void brs() {
    int n;
    string s;
    
    stack<int> st;
    ll r = 0;
    // multiplier +ve for multiplication, -ve for addition
    ll idx = 1, mul = 1, ci, tmp;
    cin >> n;
    vector<ll> v(n + 1);
    while (n--) {
        cin >> s;
        if (s == "(") {
            st.push(idx * mul);
            mul *= -1;
        } else if (s == ")") {
            ci = st.top();
            st.pop();
            // addition
            if (ci < 0) {
                ci = -ci;
                tmp = 0;
                for (int i = ci; i < idx; i++) {
                    tmp += v[i] % MOD;
                    tmp %= MOD;
                }
                mul = -1;
            } else { // multiplication
                tmp = 1;
                for (int i = ci; i < idx; i++) {
                    tmp *= v[i] % MOD;
                    tmp %= MOD;
                }
                mul = 1;
            }
            v[ci] = tmp;
            idx = ci + 1;
        } else {
            v[idx++] = stoi(s);
        }
    }
    tmp = 0;
    for (int i = 1; i < idx; i++) {
        tmp += v[i] % MOD;
        tmp %= MOD;
    }
    cout << tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    brs();
    return 0;
}
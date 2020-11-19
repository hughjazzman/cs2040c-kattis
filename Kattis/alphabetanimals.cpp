#include <iostream>
#include <string>
#include <vector>

using namespace std;

void alph() {
    string s;
    vector<string> v;
    int n, cnt[256] = {0};
    cin >> s >> n;
    char last = s.back();
    while (n--) {
        cin >> s;
        char fr = s.front();
        cnt[fr]++;
        if (fr == last)
            v.push_back(s);
    }
    bool b = false;
    for (string s : v) {
        char cfr = s.front(), cbk = s.back();
        if (cnt[cbk] == 0 || (cnt[cbk] == 1 && cfr == cbk)) {
            cout << s << '!';
            b = true;
            break;
        }
    }
    if (b) return;
    if (!v.empty())
        cout << v.front();
    else
        cout << '?';
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    alph();
    return 0;
}
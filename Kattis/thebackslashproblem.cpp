#include <iostream>
#include <string>

using namespace std;

void bslp() {

    bool b[256] = {0};
    for (char c = '!'; c <= '*'; ++c)
        b[c] = true;
    for (char c = '['; c <= ']'; ++c)
        b[c] = true;

    int n;
    string s;
    while (cin >> n) {
        cin.ignore();
        getline(cin, s);
        string o((1 << n) - 1, '\\');
        for (char c : s) {
            if (b[c])
                cout << o;
            cout << c;
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    bslp();
    return 0;
}
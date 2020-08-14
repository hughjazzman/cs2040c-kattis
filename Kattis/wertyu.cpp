#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string r1 = "`1234567890-=", r2 = "QWERTYUIOP[]\\";
    string r3 = "ASDFGHJKL;'", r4 = "ZXCVBNM,./";
    char t[256] = { 0 };

    t[' '] = ' ';

    for (string s : {r1, r2, r3, r4}) {
        for (int i = 1; i < s.size(); i++)
            t[s[i]] = s[i - 1];
    }

    string s;

    while (getline(cin, s)) {
        for (char c : s) {
            cout << t[c];
        }
        cout << '\n';
    }    

    return 0;
}
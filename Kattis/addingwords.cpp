#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

void addw() {
    string line, s, x, c;
    int y;
    unordered_map<string, int> mp;
    unordered_map<int, string> mpis;
    while (getline(cin, line)) {
        istringstream iss(line);
        iss >> s;
        if (s == "def") {
            iss >> x >> y;
            if (mp.count(x))
                mpis.erase(mp[x]);
            mp[x] = y;
            mpis[y] = x;
        } else if (s == "calc") {
            c = "+";
            int r = 0;
            bool b = true;
            while (iss >> s) {
                if (!mp.count(s))
                    b = false;
                else if (c == "+")
                    r += mp[s];
                else if (c == "-")
                    r -= mp[s];
                iss >> c;
        
                cout << s << ' ' << c << ' ';
            }
            if (b && mpis.count(r))
                cout << mpis[r];
            else
                cout << "unknown";
            cout << '\n';
        } else {
            mp.clear();
            mpis.clear();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    addw();
    return 0;
}
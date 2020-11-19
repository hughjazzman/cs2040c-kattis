#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void asign() {
    vector<string> v = {"Aquarius","Pisces", "Aries","Taurus","Gemini","Cancer",
            "Leo","Virgo","Libra","Scorpio","Sagittarius","Capricorn"};
    vector<string> mon = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    int day[] = {21,20,21,21,21,22,23,23,22,23,23,22};
    unordered_map<string, int> mp;
    int i = 0;
    for (string s : mon)
        mp[s] = i++;
    
    int t, d;
    string m;
    cin >> t;
    while (t--) {
        cin >> d >> m;
        i = mp[m];
        if (d < day[i])
            --i;
        if (i < 0)
            i = 11;
        cout << v[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    asign();
    return 0;
}
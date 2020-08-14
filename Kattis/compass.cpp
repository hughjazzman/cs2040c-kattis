#include <iostream>

using namespace std;

int main() {
    int n1, n2, a;
    cin >> n1 >> n2;
    a = n2 - n1;
    if (a > 180)
        a -= 360;
    else if (a <= -180)
        a += 360;
    cout << a;
}
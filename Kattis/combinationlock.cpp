#include <iostream>
#include <stdio.h>
using namespace std;

#define NUM_DIG 4

int dig(int start, int end, int dir) {
    int d = end - start;
    if (dir) d = -d;
    d += 40;
    return d % 40;
    
}

int dig_mov(int n[]) {
    int res = 0;
    for (int i = 0; i < NUM_DIG - 1; i++) {
        res += dig(n[i], n[i + 1], i % 2 == 0);
    }
    return res;
}

int arr_is_empty(int n[]) {
    for (int i = 0; i < NUM_DIG; i++) {
        if (n[i]) return 0;
    }
    return 1;
}

int main()
{
    int n[4], total;
    while (1) {
        total = 120;

        cin >> n[0] >> n[1] >> n[2] >> n[3];
        if (arr_is_empty(n)) return 0;

        total += dig_mov(n);

        cout << total*9 << endl;
    }
}
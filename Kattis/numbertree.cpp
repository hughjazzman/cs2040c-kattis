#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector
#include <string>
#include <math.h>
#include <numeric>		// std::iota

using namespace std;

int traverse(string path) {
	int n = 0;
	for (char &i : path) {
		if (i == ' ') continue;
		n *= 2; n++;
		if (i == 'R') n++;
	}
	return n;
}

void numtree() {
	int h;
	string path;
	
	cin >> h;
	getline(cin, path);

	cout << (int)pow(2, h+1) - 1 - traverse(path);
}

int main() {
    numtree();
    return 0;
}
#include <vector>
#include <iostream>

#define FOR(i,k) for(int i=0;i<k;i++)

#define MAX (int)(1e9 + 7)
#define SIZE 4000

using namespace std;

// for debugging
void print(vector<vector<bool>> & g, int V) {
	FOR(i, V) {
		FOR(j, V) {
			cout << g[i][j] << ' ';
		}
		cout << endl;
	}
}

void com(vector<vector<bool>> & g, int qn, bool *tp, bool *tr, bool *fl, int *V) {
	int x, y;

	switch (qn)
	{
	case 1: // add vertex
		FOR(i, (*V) + 1) {
			g[i][*V] = *fl;
			g[*V][i] = *fl;
		}
		(*V)++;
		break;
	case 2: // add edge
		cin >> x >> y;
		if (*tp)
			g[y][x] = *tr;
		else
			g[x][y] = *tr;
		break;
	case 3: // remove all edges in/out of vertex
		cin >> x;
		FOR(i, *V) {
			g[i][x] = *fl;
			g[x][i] = *fl;
		}
		break;
	case 4: // remove edge
		cin >> x >> y;
		if (*tp)
			g[y][x] = *fl;
		else
			g[x][y] = *fl;
		break;
	case 5: // transpose
		*tp = !*tp;
		break;
	case 6: // complement
		FOR(i, *V) 
			g[i][i] = *tr;
		swap(*tr, *fl);
		break;
	default:
		break;
	}
}

void ab() {
	int V, E, Q, A, B, qn;
	//transpose, true, false
	bool tp = false, tr = true, fl = false;
	cin >> V >> E >> Q;
	vector<vector<bool>> g(SIZE, vector<bool>(SIZE, fl));
	while (E--) {
		cin >> A >> B;
		g[A][B] = tr;
	}
	while (Q--) {
		cin >> qn;
		com(g, qn, &tp, &tr, &fl, &V);
	}
	cout << V << '\n';
	FOR(i, V) {
		long k = 0, h = 0, m = 1;
		FOR(j, V) {
			if (tp && (g[j][i] ^ tr) || !tp && (g[i][j] ^ tr)) continue;
			
			m %= MAX;
			h += (m * j);
			m *= 7;
			k++;
		}
		h %= MAX;
		cout << k << ' ' << h << '\n';
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ab();
    return 0;
}
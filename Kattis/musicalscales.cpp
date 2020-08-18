// Without using std::map

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define FOR(i, n) for(int i=0;i<n;i++)

int noteIdx(string s) {
	int res = s[0] - 'A';
	if (s.size() == 2)
		res += 7;
	return res;
}

string idxNote(int i) {
	string s;
	
	if (i > 6) {
		i -= 7;
		s.push_back(i + 'A');
		s.push_back('#');
	} else
		s.push_back(i + 'A');
	return s;
}

void music() {
	// cin var
	int n, s_i, nt_i;
	string s, c_nt;

	// bool array for answer
	bool res[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	bool ch[14] = {};
	
	// scale progression
	int scale_prog[] = {2,2,1,2,2,2,1,2};

	// boolean array for notes in each scale
	bool arr[14][14] = { 0 };
	vector<string> nts = {"A","A#","B","C","C#","D", "D#","E","F","F#","G","G#"};
	vector<int> nts_i;
	for (string nt : nts)
		nts_i.push_back(noteIdx(nt));

	// get notes in each scale
	FOR(i, 12) {
		// current note
		string nt = nts[i];
		// starting index, note index, current scale index
		int i_i = i, idx = noteIdx(nt), c_idx = idx;
		FOR(j, 8) {
			// at current scale, note exists
			arr[c_idx][idx] = true;
			// move to next index
			i_i += scale_prog[j];
			if (i_i > 11) 
				i_i %= 12;
			// convert to note index
			nt = nts[i_i];
			idx = noteIdx(nt);
		}
	}

	bool b = true;
	cin >> n;
	while (n--) {
		cin >> s;
		s_i = noteIdx(s);
		if (ch[s_i]) continue;
		ch[s_i] = true;
		// check each scale
		FOR(i, 12) {
			// convert note scale to note index
			c_nt = nts[i];
			nt_i = noteIdx(nts[i]);
			res[nt_i] &= arr[nt_i][s_i];
		}
	}

	for (int i : nts_i) {
		if (res[i]) {
			b = false;
			cout << idxNote(i) << ' ';
		}
	}

	if (b) cout << "none";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    music();
    return 0;
}
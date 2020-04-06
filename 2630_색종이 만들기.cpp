#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos {
	int s_x, s_y, d_x, d_y;
};

bool checkpaper(vector<vector<bool> > paper, Pos chk, int a);

int main() {
	int N = 0, count_white = 0, count_blue = 0;
	cin >> N;

	vector<vector<bool> > paper(N + 1, vector<bool>(N + 1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			bool temp;
			cin >> temp;
			paper[i][j] = temp;
		}
	}

	queue<Pos> checklist;
	checklist.push({ 1, 1, N, N});

	while (!checklist.empty()) {

		Pos chk = checklist.front();
		checklist.pop();

		bool c_white = checkpaper(paper, chk, 0);
		bool c_blue = checkpaper(paper, chk, 1);
		count_white += c_white;
		count_blue += c_blue;

		if (c_white == 0 && c_blue == 0) {
			checklist.push({ chk.s_x, chk.s_y, (chk.s_x + chk.d_x) / 2, (chk.s_y + chk.d_y) / 2});
			checklist.push({ ((chk.s_x + chk.d_x) / 2) + 1, chk.s_y, chk.d_x, (chk.s_y + chk.d_y) / 2});
			checklist.push({ chk.s_x, (chk.s_y + chk.d_y) / 2 + 1 , ((chk.s_x + chk.d_x) / 2), chk.d_y });
			checklist.push({ ((chk.s_x + chk.d_x) / 2) + 1, ((chk.s_y + chk.d_y) / 2) + 1, chk.d_x, chk.d_y });
		}
	}

	cout << count_white << endl << count_blue << endl;

	return 0;
}

bool checkpaper(vector<vector<bool> > paper, Pos chk, int a) {
	for (int i = chk.s_x; i <= chk.d_x; i++) {
		for (int j = chk.s_y; j <= chk.d_y; j++) {
			if (paper[i][j] != a) return false;
		}
	}

	return true;
}

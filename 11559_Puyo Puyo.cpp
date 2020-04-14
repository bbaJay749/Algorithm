#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Pos {
	int x, y;
};

int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

void counter(int i, int j);
vector<vector<char> > puyopuyo(12, vector<char>(6));
vector<vector<bool> > visit(12, vector<bool>(6));
queue<Pos> bunch;
bool boom_flag = true;	// this flag checks pop exists or not 

int main() {
	int count = 0;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> puyopuyo[i][j];
		}
	}

	while (boom_flag) {

		boom_flag = false;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				/* find every bunches which are biggger than 4 and pop them */

				if (visit[i][j] == false && puyopuyo[i][j] != '.') {
					visit[i][j] = true;
					bunch.push({ i, j });
					counter(i, j);
				}

				if (bunch.size() >= 4) {
					boom_flag = true;
					while (!bunch.empty()) {
						Pos p = bunch.front();
						bunch.pop();
						puyopuyo[p.x][p.y] = '.';
					}
				}
				else {
					while (!bunch.empty()) {
						bunch.pop();
					}
				}
			}
		}

		visit = vector<vector<bool> >(12, vector<bool>(6, false));

		if (boom_flag) count++;
		for (int i = 10; i >= 0; i--) {
			for (int j = 5; j >= 0 ; j--) {
				if (puyopuyo[i][j] != '.') {
					int q = i;

					while (q < 11 && puyopuyo[q + 1][j] == '.') {
						q++;
					}

					if (q != i && puyopuyo[q][j] == '.') { // if there are any change
						puyopuyo[q][j] = puyopuyo[i][j];
						puyopuyo[i][j] = '.';
					}
				}
			}
		}
	}
	
	cout << count << '\n';

	return 0;
}

void counter(int i, int j) {
	for (int d = 0; d < 4; d++) {
		int x = i + dir[d][0], y = j + dir[d][1];
		if (x >= 0 && x < 12 && y >= 0 && y < 6) {	// should be on the map
			if (visit[x][y] == false){
				if (puyopuyo[x][y] == puyopuyo[i][j]) {
					visit[x][y] = true;
					bunch.push({ x, y });
					counter(x, y);
				}
			}
		}
	}
}

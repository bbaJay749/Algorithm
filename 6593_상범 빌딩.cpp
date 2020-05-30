#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos {
	int x, y, z, time;
}; 
vector<vector<int> >  dir = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1} };
int L, R, C;
Pos S, E;

int bfs(vector<vector<vector<char> > > building) {
	vector<vector<vector<bool> > > visit(L, vector<vector<bool> >(R, vector<bool>(C, false)));
	queue<Pos> porBFS; 
	porBFS.push(S);

	while (!porBFS.empty()) {
		Pos current = porBFS.front();
		porBFS.pop();

		if (current.x == E.x && current.y == E.y && current.z == E.z) {
			/* queue need to be empty everytime
			while (!porBFS.empty()) {
				porBFS.pop();
			}
			*/
			return current.time;
		}

		for (int i = 0; i < 6; i++) {
			/* range check */
			if (current.x + dir[i][0] >= 0 && current.x + dir[i][0] < L) {
				if (current.y + dir[i][1] >= 0 && current.y + dir[i][1] < R) {
					if (current.z + dir[i][2] >= 0 && current.z + dir[i][2] < C) {
						/* map check */
						if (building[current.x + dir[i][0]][current.y + dir[i][1]][current.z + dir[i][2]] != '#') {
							/* visit check */
							if (!visit[current.x + dir[i][0]][current.y + dir[i][1]][current.z + dir[i][2]]) {
								visit[current.x + dir[i][0]][current.y + dir[i][1]][current.z + dir[i][2]] = true;
								porBFS.push({ current.x + dir[i][0], current.y + dir[i][1], current.z + dir[i][2], current.time + 1 });
							}
						}
					}
				}
			}
		}

		if (porBFS.empty()) return -1;
	}
	
}

int main() {

	for (;;) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;

		/* get the map of Sangbum building */
		vector<vector<vector<char> > > building(L, vector<vector<char> >(R, vector<char>(C)));
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> building[i][j][k];
					if (building[i][j][k] == 'S') {
						S.x = i; S.y = j; S.z = k; S.time = 0;
					}
					else if (building[i][j][k] == 'E') {
						E.x = i; E.y = j; E.z = k; E.time = 0;
					}
				}
			}
		}

		int result = bfs(building);
		if (result == -1) {
			cout << "Trapped!" << "\n";
		}
		else {
			cout << "Escaped in " << result << " minute(s).\n";
		}
	}

	return 0;
}

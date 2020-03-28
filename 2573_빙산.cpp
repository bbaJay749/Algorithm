#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct Pos {
	int x, y, sea;
};
void melt(int N, int M, vector<vector <int>> pole, queue<Pos> iceberg);
bool isWhole(int N, int M, vector<vector <int>> pole, queue<Pos> iceberg);

int main() {
	int N = 0, M = 0;
	cin >> N >> M;

	vector<vector <int>> pole(N, vector<int>(M, 0));

	queue<Pos> iceberg;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> pole[i][j];

			if (pole[i][j] != 0) {
				iceberg.push({ i, j, 0 });
			}
		}
	}

	melt(N, M, pole, iceberg);

	return 0;
}

void melt(int N, int M, vector<vector <int>> pole, queue<Pos> iceberg) {
	int yrs = 0;

	while (1) {
		if (iceberg.size() < 2) {	// if the num of the iceberg pieces is less than 2
			yrs = 0; // it cannot turn into 2 icebergs
			break;
		}

		int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	
		++yrs; // year passes
		int len = iceberg.size(); // num of iceberg pieces
		for (int i = 0; i < len; i++) {	// check UDLR
			Pos p = iceberg.front();
			iceberg.pop();

			for (int d = 0; d < 4; d++) {
				int x = p.x + dir[d][0], y = p.y + dir[d][1];
				if (x >= 0 && x < N && y >= 0 && y < M) {
					if (pole[x][y] == 0) {
						p.sea++;	// if it's 0, it means it's sea
					}
				}
			}

			iceberg.push(p);
		}

		for (int i = 0; i < len; i++) {	// check the heights of the iceberg pieces 
			Pos p = iceberg.front();
			iceberg.pop();

			pole[p.x][p.y] -= p.sea;
			if (pole[p.x][p.y] < 0) pole[p.x][p.y] = 0;
			else if (pole[p.x][p.y] > 0) {
				p.sea = 0;
				iceberg.push(p);
			}
		}

		// if iceberg is not empty and it's not 1
		if (!iceberg.empty() && isWhole(N, M, pole, iceberg) == false) {
			break;
		}
	}

	cout << yrs << endl;
}

bool isWhole(int N, int M, vector<vector <int>> pole, queue<Pos> iceberg) {
	queue<Pos> q;	// queue of BFS (너비우선)
	q.push(iceberg.front());

	vector<vector <bool>> visit(N, vector<bool>(M, 0));
	int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

	int num = 0;
	while (!q.empty()) {
		Pos p = q.front();
		visit[p.x][p.y] = true;
		q.pop();

		++num;
		for (int d = 0; d < 4; d++) {
			int x = p.x + dir[d][0], y = p.y + dir[d][1];
			if (x >= 0 && x < N && y >= 0 && y < M) {
				/* if the height of the iceberg is more than 0 and haven't visited */
				if (pole[x][y] != 0 && visit[x][y] == 0) {
					visit[x][y] = 1;
					q.push({ x, y, 0 });
				}
			}
		}
	}

	// there's only 1 iceberg, num should be same with the num of the iceberg pieces
	if (num == iceberg.size()) { 
		return true;
	}
	else { // if not, it's more than 2 icebergs
		return false;
	}
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
using namespace std;

int K, W, H;
int temp;
int INF = 987654321;
int K_min = INF;
vector<pair<int, int> > pos_H = { { -1, -2 },{ -2, -1 },{ -2, 1 },{ -1, 2 },{ 1, -2 },{ 2, -1 },{ 2, 1 },{ 1, 2 } };
vector<pair<int, int> > pos_M = { { -1, 0 },{ 0, 1 },{ 0, -1 },{ 1, 0 } };

void BFS(vector<vector<vector<int>>> visit, vector<vector<bool> > map) {
	queue<tuple <int, int, int> > paraBFS;
	paraBFS.push({ 0, 0, 0 });
	visit[0][0][0] = 0;

	while (!paraBFS.empty()) {
		tuple<int, int, int> Pos = paraBFS.front();
		paraBFS.pop();

		if (get<0>(Pos) == H - 1 && get<1>(Pos) == W - 1) {
			if (K_min > visit[H - 1][W - 1][get<2>(Pos)]) K_min = visit[H - 1][W - 1][get<2>(Pos)];
		}

		/* horse move */
		for (int i = 0; i < 8; i++) {
			int nx = get<0>(Pos) + pos_H[i].first;
			int ny = get<1>(Pos) + pos_H[i].second;
			int nk = get<2>(Pos);

			/* within valid range*/
			if (nx < H && nx >= 0 && ny < W && ny >= 0) {
				/* there shouldn't be wall*/
				if (!map[nx][ny] && get<2>(Pos) < K) {
					if (visit[get<0>(Pos)][get<1>(Pos)][nk] + 1 < visit[nx][ny][nk + 1]) {
						visit[nx][ny][nk + 1] = visit[get<0>(Pos)][get<1>(Pos)][nk] + 1;
						paraBFS.push({ nx, ny, nk + 1 });
					}
				}
			}
		}
	
		/* monkey move */
		for (int k = 0; k < 4; k++) {
			int nx = get<0>(Pos) + pos_M[k].first;
			int ny = get<1>(Pos) + pos_M[k].second;
			int nk = get<2>(Pos);

			/* within valid range*/
			if (nx < H && nx >= 0 && ny < W && ny >= 0) {
				/* there shouldn't be wall*/
				if (!map[nx][ny]) {
					if (visit[get<0>(Pos)][get<1>(Pos)][nk] + 1 < visit[nx][ny][nk]) {
						visit[nx][ny][nk] = visit[get<0>(Pos)][get<1>(Pos)][nk] + 1;
						paraBFS.push({ nx, ny, nk });
					}
				}
			}
		}
	}
}


int main() {
	cin >> K >> W >> H;

	vector<vector<bool> > map(H, vector<bool>(W));
	vector<vector<vector<int>>> visit(H, vector<vector<int>>(W, vector<int>(K + 1, INF)));

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> temp;
			if (temp == 1) map[i][j] = true;
			else if (temp == 0) map[i][j] = false;
		}
	}

	BFS(visit, map);

	if (K_min == INF) cout << -1 << "\n";
	else cout << K_min << "\n";

	return 0;
}
